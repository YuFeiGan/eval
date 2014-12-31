// #include <cblas.h>
#include "math_functions.hpp"
#include <stdio.h>
// using namespace gyf;
#include <iostream>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>

using std::cout;
using std::endl;
using namespace boost::numeric::ublas;


namespace gyf {
double ddot(const vector<double> A, const vector<double> B) {
    assert(A.size() == B.size());
    int n = A.size();
    double x[A.size()];
    double y[B.size()];
    for (int i = 0; i < n; ++i) {
        x[i] = A(i);
        y[i] = B(i);
    }
    return cblas_ddot(n, x, 1, y, 1);
};
}

// int main() {
//     vector<double> A(9);
//     vector<double> B(9);
//     double C[9];
//     for (int i = 0; i < 9; ++i) {
//         A(i) = i;
//         B(i) = i;
//         C[i] = i;
//     }
//     // boost::numeric::ublas::vector<class T>
//     // cblas_dgemm(CblasColMajor, CblasNoTrans, CblasTrans, 3, 3, 2, 1, A, 3, B, 3, 2, C, 3);
//     cout << A << endl;
//     cout << B << endl;
//     cout << gyf::ddot(A, B) << endl;

//     return 0;
// }