#include <sophus/se3.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>

// need pangolin for plotting trajectory
#include <pangolin/pangolin.h>

using namespace std;

// function for plotting trajectory, don't edit this code
// start point is red and end point is blue
void DrawTrajectory(const std::vector<Sophus::SE3d, Eigen::aligned_allocator<Sophus::SE3d>> &gt_poses,
                    const std::vector<Sophus::SE3d, Eigen::aligned_allocator<Sophus::SE3d>> &es_poses)
{
  if (gt_poses.empty() || es_poses.empty()) 
  {
    cerr << "Trajectory is empty!" << endl;
    return;
  }

  // create pangolin window and plot the trajectory
  pangolin::CreateWindowAndBind("Trajectory Viewer", 1024, 768);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  pangolin::OpenGlRenderState s_cam(
    pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
    pangolin::ModelViewLookAt(0, -0.1, -1.8, 0, 0, 0, 0.0, -1.0, 0.0)
  );

  pangolin::View &d_cam = pangolin::CreateDisplay()
    .SetBounds(0.0, 1.0, pangolin::Attach::Pix(175), 1.0, -1024.0f / 768.0f)
    .SetHandler(new pangolin::Handler3D(s_cam));


  while (pangolin::ShouldQuit() == false) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    d_cam.Activate(s_cam);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glLineWidth(2);
    for (size_t i = 0; i < gt_poses.size() - 1; i++) {
      glColor3f(0.0f, 1.0f, 0.0f);
      glBegin(GL_LINES);
      auto p1 = gt_poses[i], p2 = gt_poses[i + 1];
      glVertex3d(p1.translation()[0], p1.translation()[1], p1.translation()[2]);
      glVertex3d(p2.translation()[0], p2.translation()[1], p2.translation()[2]);
      glEnd();
    }

    for (size_t i = 0; i < es_poses.size() - 1; i++) {
      glColor3f(1.0f, 0.0f, 0.0f);
      glBegin(GL_LINES);
      auto p1 = es_poses[i], p2 = es_poses[i + 1];
      glVertex3d(p1.translation()[0], p1.translation()[1], p1.translation()[2]);
      glVertex3d(p2.translation()[0], p2.translation()[1], p2.translation()[2]);
      glEnd();
    }
    pangolin::FinishFrame();
    usleep(5000);   // sleep 5 ms
  }
}

void readTrajectory(std::vector<Sophus::SE3d, Eigen::aligned_allocator<Sophus::SE3d>> &poses, const std::string filename)
{
  ifstream trajectory_file(filename);
  while (!trajectory_file.eof())
  {
    double t, t_x, t_y, t_z, q_x, q_y, q_z, q_w;
    trajectory_file >> t >> t_x >> t_y >> t_z >> q_x >> q_y >> q_z >> q_w;
    poses.emplace_back(Sophus::SE3d(Eigen::Quaterniond{q_w, q_x, q_y, q_z}, Eigen::Vector3d(t_x, t_y, t_z)));
  }

  trajectory_file.close();
}

double computeRMSE();

int main(int argc, char **argv) {
  // path to trajectory file
  string gt_filename = "../groundtruth.txt";
  string es_filename = "../estimated.txt";

  vector<Sophus::SE3d, Eigen::aligned_allocator<Sophus::SE3d>> gt_poses, es_poses;
  
  readTrajectory(gt_poses, gt_filename);
  readTrajectory(es_poses, es_filename);

  // computeRMSE(gt_poses, es_poses);
  DrawTrajectory(gt_poses, es_poses);
  return 0;
}