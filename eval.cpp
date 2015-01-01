#include "eval.hpp"
#include "math_functions.hpp"
bool sort_distance(const distance& left, const distance& right){
	return (double)left.first < (double)right.first;
};

void eval::preproc(){
	// normalize vector
	for (int i = 0; i < data.size(); ++i){
		double t;
		for (int j = 0; j < data[i].first.size(); ++j){
			if (t < data[i].first[j]) t = data[i].first[j];
		}
		data[i].first /= t;
	}
};
void eval::compdistance(){
	for (int i = 0; i < data.size(); ++i){
		// computing i th feature's distance
		distance_feat distan_feat;
		// input i th feature's label
		distan_feat.second = data[i].second;
		// computing the distance between i th feature and j th feature 
		for (int j = 0; j < data.size(); ++j){
			// feature t_feature = data[i].first - data[j].first; 
			// distance t_dis(norm_1(element_prod(t_feature, t_feature)), data[j].second);
			// distance t_dis(gyf::ddot(t_feature, t_feature), data[j].second);
			distance t_dis(gyf::computedis(data[i].first, data[j].first), data[j].second);
			// input distance into i th feature
			distan_feat.first.push_back(t_dis);
		}
		distan.push_back(distan_feat);
	}
};
void eval::sort(){
	// sort distance data
	assert(data.size()==distan.size());
	for (int i = 0; i < data.size(); ++i){
		std::sort(distan[i].first.begin(), distan[i].first.end(), sort_distance);
	}
	issort = true;
};
void eval::getplotdata(int maxnum){
	// "maxnum must be larger than the number of data"
	if(maxnum > data.size()) {
		std::cerr<<"maxnum can't be larger than the number of data!! and data.size() = "<<data.size()<<endl;
		exit(1);
	}
	if(!issort) {
		std::cerr<<"data must be sorted!"<<endl;
		exit(1);
	}

	for (int i = 0; i < distan.size(); ++i){
		vector<double> t_plot(maxnum);
		double retrieved = 0;
		for (int j = 0; j < distan[0].first.size(); ++j){
			if (distan[i].second == distan[i].first[j].second)
				retrieved++;
			if (j < maxnum)
				t_plot(j) = retrieved;		
		}
		t_plot = t_plot/retrieved;
		// display(t_plot);
		plotdata.push_back(t_plot);
	}
	// plotend()
	vector<double> t_plotend(plotdata[0].size());
	for (int i = 0; i < t_plotend.size(); ++i){
		double count_ = 0.0;
		for (int j = 0; j < plotdata.size(); ++j){
			count_ += plotdata[j](i);
		}
		t_plotend(i) = count_;
	}
	plotend = t_plotend / plotdata.size();
	isgetplotdata = true;
};


void display(const matrix<double> mat){
	cout<<"matrix---------"<< mat.size1()
		<< "x"<< mat.size2()<< "---------"<<endl;
	for (int i = 0; i < mat.size1(); ++i)
	{
		for (int j = 0; j < mat.size2(); ++j)
		{
			cout<<mat(i,j)<< " ";
		}
		cout<<endl;
	}
	cout<<endl;
};
void display(const vector<double> vec){
	// cout<<"vector----------"<< vec.size()<< "----------"<<endl;
	for (int i = 0; i < vec.size(); ++i){
		cout<<vec(i)<< " ";
	}
	cout<<endl;
};
void display(const labeled_feat feature){
	cout<<"labeled_feat--"<< feature.first.size()<< "----------"<<endl;
	for (int i = 0; i < feature.first.size(); ++i)
	{
		cout<<feature.first(i)<< " ";
	}
	cout<<endl;
};
void display(const labeled_data features){
	cout<<"labeled_data--"<< features.size()<<"x"<<features[0].first.size()<< "----------"<<endl;
	for (int i = 0; i < features.size(); ++i)
	{
		cout<< "label:"<<features[i].second <<" &";
		for (int j = 0; j < features[i].first.size(); ++j)
		{
			cout<<features[i].first[j]<< " ";
		}
		cout<<endl;
	}
	cout<<endl;
};
void display(const distance_data dis_data){
	cout<<"distance_data--"<< dis_data.size()<< "----------"<<endl;
	for (int i = 0; i < dis_data.size(); ++i)
	{
		cout<< i<< "th feature's label: " <<dis_data[i].second<<endl;
		for (int j = 0; j < dis_data[i].first.size(); ++j)
		{
			cout<< "distance: " << dis_data[i].first[j].first
				<< " label: "<<dis_data[i].first[j].second<<endl;
		}
		cout<<"------------"<<endl;
	}
};
void display(const std::vector<vector<double> > plotd){
	cout<<"plotd--"<< plotd.size()<<"x"<< plotd[1].size()<< "----------"<<endl;
	for (int i = 0; i < plotd.size(); ++i){
		for (int j = 0; j < plotd[i].size(); ++j){
			cout<<plotd[i](j)<< " ";
		}
		cout<<endl;
	}
};

