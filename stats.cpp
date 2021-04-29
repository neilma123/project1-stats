// stats.cpp
#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

vector<vector<double> > summarize(vector<double> v) {
    
//    sort to address the need for a sorted finished product
    
    sort(v);
    const double epsilon = 0.00001;
//    create dummy vector to store all unique numbers in the original dataset v
    
    vector<double> temp = {v[0]};
    size_t j = 0;
    
//    fill the vector with only the unique numbers to be copied into vector of vectors later
    for (size_t i = 0; i < v.size(); i++){
        for (j = j; j < temp.size();){
            if (abs(temp[j] - v[i]) < epsilon){
                break;
            }
            else {
                temp.push_back(v[i]);
                j++;
                break;
            }
        }
    }
    
//    copy the unique values from the second list to the vector of vectors
    
    vector<vector<double>> vecOfVec;
    for (size_t i = 0; i < temp.size(); i++){
        vecOfVec.push_back({temp[i], 0});
    }
    
//    add 1 to the frequency slot of the vector of vectors for every time the unique value is found
    
    for (size_t i = 0; i < temp.size(); i++){
        int sum = 0;
        for (size_t j = 0; j < v.size(); j++){
            if (abs(temp[i] - v[j]) < epsilon){
                sum += 1;
                vecOfVec[i][1] = sum;
            }
        }
    }
    
    return vecOfVec;
}

int count(vector<double> v) {
    return (int) v.size();
}

double sum(vector<double> v) {
    double total = 0;
    for (size_t i = 0; i < v.size(); i++){
        total += v[i];
    }
    return total;
}

double mean(vector<double> v) {
//    Assuming the sum and count functions work, it's just the sum divided by the number of terms.
    return sum(v)/count(v);
}

double median(vector<double> v) {
    sort(v);
//    odd number case for median
    if (v.size() % 2 == 1){
        double size = static_cast<double>(v.size());
        size = size/2;
        size = ceil(size);
        size = size - 1;
        size = v[size];
        return size;
    }
//    even number case for median
    else if (v.size() % 2 == 0){
        double size = static_cast<double>(v.size());
        double size2;
        size = size/2;
        size2 = size + 1;
        size -= 1;
        size2 -= 1;
        size = v[size];
        size2 = v[size2];
        size = (size + size2) / 2;
        return size;
    }
    return 0;
}

double mode(vector<double> v) {
//    Essentially maximize the second dimension of the vector of vectors in summarize then return the value that is attached to the highest frequency in summarize.
    vector<vector<double>> v1 = summarize(v);
    double max = v1[0][1];
    int maxPos = 0;
    for (size_t i = 0; i < v1.size(); i++){
        if (v1[i][1] > max){
            max = v1[i][1];
            maxPos = (int) i;
        }
        else if (v1[i][1] == max){
            if (v1[i][0] < v1[maxPos][0]){
                maxPos = (int) i;
                max = v1[i][1];
            }
        }
    }
    return v1[maxPos][0];
}

double min(vector<double> v) {
//    Assuming the sort function works, the smallest value is just the first
    sort(v);
    return v[0];
}

double max(vector<double> v) {
//    Assuming the sort function works, the maximum function is just the last value
    sort(v);
    return v[v.size() - 1];
}

double stdev(vector<double> v) {
//    Standard deviation formula
    double m = mean(v);
    for (size_t i = 0; i < v.size(); i++){
        v[i] -= m;
        v[i] = pow(v[i], 2);
        v[i] = abs(v[i]);
    }
    double s = sum(v);
    double c = count(v) - 1;
    double stdev = s / c;
    stdev = sqrt(stdev);
    return stdev;
}

double percentile(vector<double> v, double p) {
//    percentile formula
    sort(v);
    double rank = p * ((v.size() - 1)) + 1;
    double fractpart = 0;
    double intpart = 0;
    fractpart = modf(rank , &intpart);
//    Edge case #1: If there is only one value it can only be the value
    if ((v.size() == 1)){
        return v[intpart - 1];
    }
//    Edge case #2: This addresses when the function leaves the vector when percentile = 1, because when percentile = 1 it should return the last value, not compare it to a point outside the vector.
    else if (p == 1){
        return v[v.size() - 1];
    }
    intpart -= 1;
    double percentile = v[intpart] + (fractpart) * (v[intpart + 1] - v[intpart]);
    return percentile;
    
}
