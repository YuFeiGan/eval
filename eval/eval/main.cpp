#include "eval.hpp"
#include "Convert.hpp"
int main () {   
	matlab2eval t0("test/output.txt");
	labeled_data features = t0.getdata();
	eval t(features);

	t.preproc();
	// t.showdata();
	t.compdistance();
	t.sort();
	// t.showdistance();
	t.getplotdata(10000);
	// t.showplotdata();
	t.showplotend();
	// t.showdata();
	// t.showdistance();
	return 0;
}
