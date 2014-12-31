#include "Convert.hpp"

labeled_data matlab2eval::getdata(){
	std::ifstream fs(filename.data());
	if (!fs){
		std::cerr<<"Failed to open file";
		exit(1);
	}
	// store into std::vector
	std::vector<std::vector<double> > t_data;
	std::string strFloat;
	double fNum;
	int counter = 0;
	while(getline(fs,strFloat)){
		std::stringstream  linestream(strFloat);
		t_data.push_back(std::vector<double>());
		while(linestream >> fNum)
			t_data[counter].push_back(fNum);
		++counter;
	}
	// convert into labeled data
	for (int i = 0; i < t_data.size(); ++i){
		feature t_feat(t_data[0].size());
		for (int j = 1; j < t_data[0].size(); ++j){
			t_feat(j-1) = t_data[i][j];
		}
		// display(t_feat);
		labeled_feat t_labeled_feat;
		t_labeled_feat.first = t_feat;
		t_labeled_feat.second = t_data[i][0];
		data.push_back(t_labeled_feat);
	} 
	return data;
};