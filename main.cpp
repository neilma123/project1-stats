//main.cpp
#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>
#include<fstream>
using namespace std;

int main(int argc, char **argv){
    cout << "enter a filename" << endl;
    string filename;
    cin >> filename;
    cout << "enter a column name" << endl;
    string column;
    cin >> column;
    cout << "reading column " << column << " from " << filename << endl;
    vector<double> v = extract_column(filename, column);
    cout << "Summary (value: frequency)" << endl;
    vector<vector<double>> vofv = summarize(v);
    for (size_t i = 0; i < vofv.size(); i++){
        cout << vofv[i][0] << ": " << vofv[i][1] << endl;
    }
    cout << endl;
    cout << "count = " << count(v) << endl;
    cout << "sum = " << sum(v) << endl;
    cout << "mean = " << mean(v) << endl;
    cout << "stdev = " << stdev(v) << endl;
    cout << "median = " << median(v) << endl;
    cout << "mode = " << mode(v) << endl;
    cout << "min = " << min(v) << endl;
    cout << "max = " << max(v) << endl;
    cout << "  0th percentile = " << percentile(v, 0) << endl;
    cout << " 25th percentile = " << percentile(v, 0.25) << endl;
    cout << " 50th percentile = " << percentile(v, 0.5) << endl;
    cout << " 75th percentile = " << percentile(v, 0.75) << endl;
    cout << "100th percentile = " << percentile(v, 1) << endl;
    return 0;
}
