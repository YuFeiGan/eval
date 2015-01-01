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

double nrm2(const vector<double> A) {
    int n = A.size();
    double x[A.size()];
    for (int i = 0; i < n; ++i) {
        x[i] = A(i);
    }
    return cblas_dnrm2(n, x, 1);
};

vector<double> axpy(const vector<double> A, const vector<double> B) {
    assert(A.size() == B.size());
    int n = A.size();
    double x[A.size()];
    double y[B.size()];
    for (int i = 0; i < n; ++i) {
        x[i] = A(i);
        y[i] = B(i);
    }
    cblas_daxpy(n, -1, x, 1, y, 1);
    vector<double> C(n);
    for (int i = 0; i < n; ++i) {
        C(i) = y[i];
    }
    return C;
};

double computedis(const vector<double> A, const vector<double> B) {
    assert(A.size() == B.size());
    int n = A.size();
    double x[A.size()];
    double y[B.size()];
    for (int i = 0; i < n; ++i) {
        x[i] = A(i);
        y[i] = B(i);
    }
    cblas_daxpy(n, -1, x, 1, y, 1);
    return cblas_dnrm2(n, y, 1);
};
}