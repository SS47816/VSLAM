#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>

int main(int argc, char** argv)
{
  Eigen::Quaterniond q1 {0.55, 0.3, 0.2, 0.2};
  q1.normalize();
  Eigen::Isometry3d T_1W(q1);
  T_1W.pretranslate(Eigen::Vector3d{0.7, 1.1, 0.2});

  Eigen::Quaterniond q2 {-0.1, 0.3, -0.7, 0.2};
  q2.normalize();
  Eigen::Isometry3d T_2W(q2);
  T_2W.pretranslate(Eigen::Vector3d{-0.1, 0.4, 0.8});

  Eigen::Vector3d p1{0.5, -0.1, 0.2};

  auto T_2P = T_2W * T_1W.inverse() * p1;

  std::cout << "p2 = " << T_2P.transpose() << std::endl;
  
  return EXIT_SUCCESS;
}