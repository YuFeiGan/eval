#include <cblas.h>
#include <boost/numeric/ublas/vector.hpp>
using namespace boost::numeric::ublas;

namespace gyf{
	double ddot(const vector<double> A, const vector<double> B);
	double nrm2(const vector<double> A);
	vector<double> axpy(const vector<double> A, const vector<double> B);
	double computedis(const vector<double> A, const vector<double> B);
}