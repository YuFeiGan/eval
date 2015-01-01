#ifndef EVAL_HPP
#define EVAL_HPP

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

void display(const matrix<double> mat);
void display(const vector<double> vec);
void display(const labeled_feat feature);
void display(const labeled_data features);
void display(const distance_data dis_data);
void display(const std::vector<vector<double> > plotd);

class eval {
  private:
    bool issort;
    bool isgetplotdata;
    // static int maxnum_;
  public:
    eval(const labeled_data input): issort(false), isgetplotdata(false), data(input) {};
    ~eval() {};
    void showdata() {
        display(data);
    };
    void showdistance() {
        display(distan);
    };
    void showplotdata() {
        if (!isgetplotdata)
            std::cerr << "must getplotdata before" << endl;
        display(plotdata);
    };
    void preproc();           //normalize vector
    void compdistance();      //computing distance
    void sort();                    //sort distance
    void getplotdata(int maxnum );             //get plot data
    void showplotend() {
        display(plotend);
    };
  protected:
    labeled_data data;
    distance_data distan;
    std::vector<vector<double> > plotdata;
    vector<double> plotend;
};

#endif