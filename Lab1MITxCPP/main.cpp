//  main.cpp
//  Lab1MITxCPP
//
//  Created by Evgeny Tolmachev on 13/07/2021.

//  CLI tool to count mean, max, min, range of a given list of integers.

//  Given a list of N integers, find its mean (as a double), maximum value, minimum value, and range. Your program will first ask for N, the number of integers in the list, which the user will input. Then the user will input N more numbers.
//  Example:
//  Three numbers are given: 2, 1, 3. The output should    be as follows:
//  Mean: 2
//  Max: 3
//  Min: 1
//  Range: 2
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> N;
    int userInp = 0;
    int userInpSize = 0;
    cout << "Number of int's in List? " << endl;
    cin >> userInpSize;
    cout << "Press enter after each number: " << endl;
    while (userInpSize > 0){
        cin >> userInp;
        N.push_back(userInp);
        --userInpSize;
    }
    
    double mean = accumulate(begin(N), end(N), 0.0)/N.size();

    auto minMax = minmax_element(begin(N),end(N));
    
    int range = *minMax.second - *minMax.first;
    
    cout << "Mean: " << mean << endl;
    cout << "Max: " << *minMax.first << endl;
    cout << "Min: " << *minMax.second << endl;
    cout << "Range: " << range << endl;
        
    return 0;
}
