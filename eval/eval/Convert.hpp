#ifndef CONVERT_HPP
#define CONVERT_HPP



#include "eval.hpp"
#include <fstream>

using namespace boost::numeric::ublas;

class matlab2eval{
public:
	matlab2eval(const std::string inputfilename){
		filename = inputfilename;
	};
	~matlab2eval(){};
	labeled_data getdata();

	std::string filename;
	labeled_data data;
};


#endif