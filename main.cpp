#include "eval.hpp"
#include "Convert.hpp"
#include <boost/date_time/posix_time/posix_time.hpp>

int main () {
    boost::posix_time::ptime start;
    boost::posix_time::ptime end;

    matlab2eval t0("test/output.txt");
    labeled_data features = t0.getdata();
    eval t(features);

    ///////////////////////////////
    t.preproc();
    ///////////////////////////////
    start = boost::posix_time::microsec_clock::local_time();
    t.compdistance0();
    end = boost::posix_time::microsec_clock::local_time();
    std::cout << "compdistance0: " << (end - start).total_seconds() << " s\n";
    ///////////////////////////////
    start = boost::posix_time::microsec_clock::local_time();
    t.sort();
    end = boost::posix_time::microsec_clock::local_time();
    std::cout << "sort: " << (end - start).total_seconds() << " s\n";
    ///////////////////////////////
    t.getplotdata(100);


    // t.showdata();
    // t.showdistance();
    return 0;
}
