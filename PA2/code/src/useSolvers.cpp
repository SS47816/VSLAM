#include <iostream>
#include <ctime>
#include <Eigen/Dense>

int main(int argc, char **argv)
{
  // 100x100 Random Matrix
  Eigen::MatrixXd Rand = Eigen::MatrixXd::Random(100, 100);
  Eigen::MatrixXd A = Rand * Rand.transpose();
  Eigen::VectorXd b_ = Eigen::VectorXd::Random(100);
  Eigen::VectorXd x_ = Eigen::VectorXd::Zero(100);

  clock_t t_start = clock();

  // LU Decomposition
  x_ = A.partialPivLu().solve(b_);
  std::cout << "time of partialPivLu() is " << 1000 * (clock() - t_start) / (double) CLOCKS_PER_SEC << "ms" << std::endl;
  std::cout << "x = " << x_.transpose() << std::endl;
  clock_t t_start = clock();

  x_ = A.fullPivLu().solve(b_);
  std::cout << "time of fullPivLu() is " << 1000 * (clock() - t_start) / (double) CLOCKS_PER_SEC << "ms" << std::endl;
  std::cout << "x = " << x_.transpose() << std::endl;
  clock_t t_start = clock();


  // QR Decomposition
  x_ = A.householderQr().solve(b_);
  std::cout << "time of householderQr() is " << 1000 * (clock() - t_start) / (double) CLOCKS_PER_SEC << "ms" << std::endl;
  std::cout << "x = " << x_.transpose() << std::endl;
  clock_t t_start = clock();

  x_ = A.colPivHouseholderQr().solve(b_);
  std::cout << "time of colPivHouseholderQr() is " << 1000 * (clock() - t_start) / (double) CLOCKS_PER_SEC << "ms" << std::endl;
  std::cout << "x = " << x_.transpose() << std::endl;
  clock_t t_start = clock();

  x_ = A.fullPivHouseholderQr().solve(b_);
  std::cout << "time of fullPivHouseholderQr() is " << 1000 * (clock() - t_start) / (double) CLOCKS_PER_SEC << "ms" << std::endl;
  std::cout << "x = " << x_.transpose() << std::endl;
  clock_t t_start = clock();


  // Cholesky Decomposition (A must be Positive Definite Matrix)
  x_ = A.llt().solve(b_);
  std::cout << "time of llt() is " << 1000 * (clock() - t_start) / (double) CLOCKS_PER_SEC << "ms" << std::endl;
  std::cout << "x = " << x_.transpose() << std::endl;
  clock_t t_start = clock();

  x_ = A.ldlt().solve(b_);
  std::cout << "time of ldlt() is " << 1000 * (clock() - t_start) / (double) CLOCKS_PER_SEC << "ms" << std::endl;
  std::cout << "x = " << x_.transpose() << std::endl;
  clock_t t_start = clock();

  return EXIT_SUCCESS;
}
