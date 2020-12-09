/**
 * Matrices and Vectors example
 * Ref: http://eigen.tuxfamily.org/dox/GettingStarted.html
*/

#include <iostream>
#include <Eigen/Dense>

const char nl = '\n';

// Setting some local defs vs. using Eigen namespace.
using MXD = Eigen::MatrixXd;
using M3D = Eigen::Matrix3d;
using VXD = Eigen::VectorXd;
using V3D = Eigen::Vector3d;


void runtime_size();
void compiletime_size();

int main() {
    // runtime_size();
    compiletime_size();
}


void runtime_size() {
    MXD mxd = MXD::Random(3,3);
    mxd = (mxd + MXD::Constant(3,3,1.2)) * 50;
    std::cout << "Matrix = " << nl << mxd << nl;
    V3D vxd(3);
    vxd << 1, 2, 3;
    std::cout << "Matrix * Vector = " << nl << mxd * vxd << nl;
}


void compiletime_size() {
    M3D mmm = M3D::Random();
    mmm = (mmm + M3D::Constant(1.2)) * 50;
    std::cout << "Matrix (3-D) = " << nl << mmm << nl;
    V3D vvv(1,2,3);
    std::cout << "Matrix (3-D) * Vector (3-D) = " << nl << mmm * vvv << nl;
}