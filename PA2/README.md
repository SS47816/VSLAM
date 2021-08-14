# VSLAM 

> by: SS47816

## PA2: Solid Body Motion in 3D Space

### Task 1: Matrix Calculation with Eigen

1. Linear System $$ Ax=b $$ has an unique solution only under the condition:  $$ rank(A) = rank(A|b) = n $$ ([reference](https://zh.wikipedia.org/wiki/%E5%A2%9E%E5%B9%BF%E7%9F%A9%E9%98%B5))
2. [Gaussian Elimination](https://zh.wikipedia.org/wiki/%E9%AB%98%E6%96%AF%E6%B6%88%E5%8E%BB%E6%B3%95): $$ Augmented Matrix (A|b) \xrightarrow{\text{elementary row operations}} Upper Triangle Matrix (U|c) \xrightarrow{\text{substitute in}} Ux=c \Longleftrightarrow Ax=b $$
3. [QR Decomposition](https://zh.wikipedia.org/wiki/QR%E5%88%86%E8%A7%A3): $$ A = Orthogonal Matrix (Q) * Upper Triangle Matrix (R) $$
4. [Cholesky Decomposition](): $$ A = Lower Triangle Matrix (L)(L^T) $$
5. See in `src/useSolvers.cpp`

### Task 2: Geometry Calculation

1. See in `src/useEigen.cpp`

### Task 3: