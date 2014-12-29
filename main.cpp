#include "eval.hpp"
#include "Convert.hpp"
int main () {   
	// ///////  init test1 data   //////////
	// int datanum = 4;
	// int featdim = 8;
	// labeled_data features;
	// for (int i = 0; i < datanum; ++i){
	// 	feature feat(featdim);
	// 	for (int j = 0; j < featdim; ++j){
	// 		feat(j) = j+i;
	// 	}
	// 	features.push_back(labeled_feat(feat,i));
	// }
	// // display(features);
	// /////////////////////////////////////

	// ///////  init test2 data   //////////
	// labeled_data features;
	// feature feat(5);
	// feat(0) = 2; feat(1) = 3; feat(2) = 2; feat(3) = 1; feat(4) = 2; 
	// features.push_back(labeled_feat(feat,1));
	// // feature feat(5);
	// feat(0) = 2; feat(1) = 5; feat(2) = 9; feat(3) = 1; feat(4) = 2; 
	// features.push_back(labeled_feat(feat,1));
	// // feature feat(5);
	// feat(0) = 2; feat(1) = 4; feat(2) = 2; feat(3) = 1; feat(4) = 2; 
	// features.push_back(labeled_feat(feat,2));
	// // feature feat(5);
	// feat(0) = 2; feat(1) = 4; feat(2) = 2; feat(3) = 1; feat(4) = 2; 
	// features.push_back(labeled_feat(feat,2));
	// // feature feat(5);
	// feat(0) = 2; feat(1) = 3; feat(2) = 2; feat(3) = 9; feat(4) = 2; 
	// features.push_back(labeled_feat(feat,2));
	// // display(features);
	// /////////////////////////////////////


	matlab2eval t0("test/output.txt");
	labeled_data features = t0.getdata();
	eval t(features);
	
	t.preproc();
	// t.showdata();
	t.compdistance();
	t.sort();
	// t.showdistance();
	t.getplotdata(1000);
	// t.showplotdata();
	t.showplotend();
	// t.showdata();
	// t.showdistance();
	return 0;
}
