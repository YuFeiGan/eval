#include <iostream>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>

using std::cout;
using std::endl;
using namespace boost::numeric::ublas;


typedef int label;                            // label e.g. 1, 2, 3, ...... 
typedef vector<double> feature;               // feature e.g. {0.11, 0.63, ..., 0.43}
typedef std::pair<double, label> distance;    // distance e.g. [3.4, 2]

typedef std::pair<feature, label> labeled_feat;    
typedef std::pair<std::vector<distance>, label> distance_feat;

typedef std::vector<labeled_feat> labeled_data;
typedef std::vector<distance_feat> distance_data;

bool sort_distance(const distance& left, const distance& right){
	return (double)left.first < (double)right.first;
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
	cout<<"vector----------"<< vec.size()<< "----------"<<endl;
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
	cout<<"plotd--"<< plotd.size()<< "----------"<<endl;
	for (int i = 0; i < plotd.size(); ++i){
		for (int j = 0; j < plotd[i].size(); ++j){
			cout<<plotd[i](j)<< " ";
		}
		cout<<endl;
	}
};

class eval{
	private:
		bool issort;
		// static int maxnum_;
	public:
		eval(const labeled_data input){ 
			issort = false;
			data = input;
			// maxnum_ = data.size();
		};
		~eval(){};
		void showdata(){ display(data);};
		void showdistance() { display(distan);};
		void showplotdata() { display(plotdata);};
		void preproc();   				//normalize vector
		void compdistance();			//computing distance
		void sort();                    //sort distance
		void getplotdata(int maxnum );             //get plot data
	protected:
		labeled_data data;
		distance_data distan;
		std::vector<vector<double> > plotdata; 
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
			feature t_feature = data[i].first - data[j].first; 
			distance t_dis(norm_1(element_prod(t_feature, t_feature)), data[j].second);
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
	assert(maxnum <= data.size()&&issort);
	for (int i = 0; i < distan.size(); ++i){
		vector<double> t_plot(distan[i].first.size());
		double retrieved = 0;
		for (int j = 0; j < distan[i].first.size(); ++j){
			if (distan[i].second == distan[i].first[j].second)
				retrieved++;
			t_plot(j) = retrieved;
		}
		t_plot = t_plot/retrieved;
		// display(t_plot);
		plotdata.push_back(t_plot);
	}
	display(plotdata);
};
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

	///////  init test2 data   //////////
	labeled_data features;
	feature feat(5);
	feat(0) = 2; feat(1) = 3; feat(2) = 2; feat(3) = 1; feat(4) = 2; 
	features.push_back(labeled_feat(feat,1));
	// feature feat(5);
	feat(0) = 2; feat(1) = 5; feat(2) = 9; feat(3) = 1; feat(4) = 2; 
	features.push_back(labeled_feat(feat,1));
	// feature feat(5);
	feat(0) = 2; feat(1) = 4; feat(2) = 2; feat(3) = 1; feat(4) = 2; 
	features.push_back(labeled_feat(feat,2));
	// feature feat(5);
	feat(0) = 2; feat(1) = 4; feat(2) = 2; feat(3) = 1; feat(4) = 2; 
	features.push_back(labeled_feat(feat,2));
	// feature feat(5);
	feat(0) = 2; feat(1) = 3; feat(2) = 2; feat(3) = 9; feat(4) = 2; 
	features.push_back(labeled_feat(feat,2));
	// display(features);
	/////////////////////////////////////


	eval t(features);
	
	t.preproc();
	// t.showdata();
	t.compdistance();
	t.sort();
	// t.showdistance();
	t.getplotdata(4);
	t.showplotdata();
	// t.showdata();
	// t.showdistance();
	return 0;
}
