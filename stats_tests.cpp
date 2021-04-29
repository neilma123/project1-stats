/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


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

void test_sum_small_data_set();

void test_summarize();
void test_count();
void test_sum();
void test_mean();
void test_median();
void test_mode();
void test_min();
void test_max();
void test_stdev();
void test_percentile();


int main()
{
    
    test_summarize();
    test_count();
    test_sum();
    test_mean();
    test_median();
    test_mode();
    test_min();
    test_max();
    test_stdev();
    test_percentile();
  

  return 0;
}

void test_sum_small_data_set()
{
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;
}
void test_summarize(){
    cout << "test_summarize" << endl;
    cout << "testing public" << endl;
    vector<vector<double>> v3 = {{6,1}, {7,1}, {8,1}, {9,1}, {10,1}};
    assert(summarize({6,7,8,9,10}) == v3);
    cout << "testing epsilon and negative" << endl;
    vector<vector<double>> v1 = {{-1.0000000001,2}, {1,3}, {2,3}, {3,3}, {4,3}};
    assert((summarize({-1.0000000001,-1, 1.00000001,1.00000001,1,2.000001,2,2,3,3,3,4,4,4}) == v1));
    cout << "testing size 1" << endl;
    vector<vector<double>> v2 = {{1,1}};
    assert((summarize({1}) == v2));
    cout << "Pass" << endl;
}
void test_count(){
    cout << "test_count" << endl;
    cout << "testing public" << endl;
    assert(count({6,7,8,9,10}) == 5);
    cout << "testing empty" << endl;
    assert(count({}) == 0);
    cout << "testing single" << endl;
    assert(count({1}) == 1);
    cout << "Pass" << endl;
}
void test_sum(){
    cout << "test_sum" << endl;
    cout << "testing public" << endl;
    assert(sum({6,7,8,9,10}) == 40);
    cout << "testing normal" << endl;
    assert(sum({1,1,1,1,1}) == 5);
    cout << "testing single and zero" << endl;
    assert(sum({0}) == 0);
    cout << "Pass" << endl;
 
}
void test_mean(){
    cout << "test_mean" << endl;
    cout << "testing public" << endl;
    assert(mean({6,7,8,9,10}) == 8);
    cout << "testing normal" << endl;
    assert(mean({1,1,1,1,1}) == 1);
    cout << "testing zero" << endl;
    assert(mean({0}) == 0);
    cout << "testing negative" << endl;
    assert(mean({-1,1}) == 0);
    cout << "Pass" << endl;
}
void test_median(){
    const double epsilon = 0.00001;
    cout << "test_median" << endl;
    cout << "testing public" << endl;
    assert(median({6,7,8,9,10}) == 8);
    cout << "testing normal" << endl;
    assert(median({1,1,1,1,1}) == 1);
    cout << "testing even and epsilon" << endl;
    assert(abs(median({1,2,3.00000001,4,5,6}) - 3.5) < epsilon);
    cout << "Pass" << endl;
}
void test_mode(){
    cout << "test_mode" << endl;
    cout << "testing public" << endl;
    assert(mode({6,7,8,9,10}) == 6);
    cout << "testing normal" << endl;
    assert(mode({1,1,2,3,4,1,1,2}) == 1);
    cout << "testing negative" << endl;
    assert(mode({-1,-1,-1,-1,-1}) == -1);
    cout << "Pass" << endl;
}
void test_min(){
    cout << "test_min" << endl;
    cout << "testing public" << endl;
    assert(min({6,7,8,9,10}) == 6);
    cout << "testing normal" << endl;
    assert(min({1,1,1,1,1}) == 1);
    cout << "Pass" << endl;
}
void test_max(){
    cout << "test_max" << endl;
    cout << "testing public" << endl;
    assert(max({6,7,8,9,10}) == 10);
    cout << "testing normal" << endl;
    assert(max({1,1,1,1,1}) == 1);
    cout << "Pass" << endl;
}
void test_stdev(){
    const double epsilon = 0.00001;
    cout << "test_stdev" << endl;
    cout << "testing public" << endl;
    assert(abs(stdev({6,7,8,9,10}) - 1.58114) < epsilon);
    cout << "testing negative and two elements" << endl;
    assert(abs(stdev({-1,1}) - 1.41421) < epsilon);
    cout << "testing normal" << endl;
    assert(stdev({1,1,1,1,1}) == 0);
    cout << "Pass" << endl;
}
void test_percentile(){
    const double epsilon = 0.00001;
    cout << "test_percentile" << endl;
    cout << "testing edge 1" << endl;
    assert(percentile({1}, .5) == 1);
    cout << "testing edge 2" << endl;
    assert(percentile({1,2,3,4,5}, 1) == 5);
    cout << "testing epsilon" << endl;
    assert((abs(percentile({1,2,3,4,5}, 0.11112223333) - 1.44448893332)) < epsilon);
    cout << "testing public" << endl;
    assert(percentile({6,7,8,9,10}, 0) == 6);
    assert(percentile({6,7,8,9,10}, 0.25) == 7);
    assert(percentile({6,7,8,9,10}, 0.5) == 8);
    assert(percentile({6,7,8,9,10}, 0.75) == 9);
    assert(percentile({6,7,8,9,10}, 1) == 10);
    cout << "Pass" << endl;
}

