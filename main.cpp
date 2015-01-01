#include "eval.hpp"
#include "Convert.hpp"
#include <ctime>

int main () {   
	std::clock_t start;
	double duration;

	start = std::clock();
	matlab2eval t0("test/output.txt");
	cout<<"test/output2.txt";
	labeled_data features = t0.getdata();
	eval t(features);
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout<<"eval t(features);"<<endl<< duration <<endl<<endl;
	// int a;

	start = std::clock();
	t.preproc();
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout<<"t.preproc();"<<endl<< duration <<endl<<endl;
	// t.showdata();

	start = std::clock();
	t.compdistance();
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout<<"t.compdistance();"<<endl<< duration <<endl<<endl;

	start = std::clock();
	t.sort();
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout<<"t.sort();"<<endl<< duration <<endl<<endl;

	// t.showdistance();
	start = std::clock();
	t.getplotdata(100);
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout<<"t.getplotdata(100);"<<endl<< duration <<endl<<endl;

	// t.showdata();
	// t.showdistance();
	return 0;
}
