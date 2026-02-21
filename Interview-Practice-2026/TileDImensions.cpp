#include<iostream>
#include <climits>
#include <string>
#include<vector>

using namespace std;

// getTileDimensions(10,6) should return the following
// [6*6, 4*4, 2*2, 2*2]



void getTileDimensions_recursive(int length, int breadth, vector<string> &op, int &curr_val) { //10,6

    if(length == 0 || breadth == 0) {
        return;
    }
    if(length == breadth) {
        op.push_back(to_string(curr_val) + 'x' + to_string(curr_val));
        return;
    }
    if(length < breadth) {
        curr_val = length;
        op.push_back(to_string(curr_val) + 'x' + to_string(curr_val));
        return getTileDimensions_recursive(length,breadth-curr_val, op, curr_val);
    }
    else {
        curr_val = breadth; // curr=6
        op.push_back(to_string(curr_val) + 'x' + to_string(curr_val));
        return getTileDimensions_recursive(length-curr_val,breadth, op, curr_val); //10,
    }
}

vector<string> getTileDimensions_iterative(int length, int breadth) {
    vector<string> output;
    int currVal;

    while (length != 0 && breadth != 0) {
        if (length == breadth) {
            string currStr = (to_string(length) + 'x' + to_string(length));
            output.push_back(currStr);
            return output;
        }
        else if (length < breadth) {
            currVal = length;
            breadth = breadth - currVal;
        }
        else {
            currVal = breadth;
            length = length - currVal;
        }
        string currStr = (to_string(currVal) + 'x' + to_string(currVal));
        output.push_back(currStr);
        //string currString =
    }
    return output;
}

int main() {
    vector<string> output;
    int length = 10;
    int breadth = 6;
    int curr_val = INT_MIN;
    getTileDimensions_recursive(length,breadth, output, curr_val);
    for(auto o : output) {
        cout << o << endl;
    }
    vector<string> output_iterative = getTileDimensions_iterative(length,breadth);
    for(auto o : output_iterative) {
        cout << o << endl;
    }
    return 0;
}

//time_complexity:

//      worst time complexity
        //length - breadth
        //O(min(length,breadth)) ->worst case time complexity
        //O(1) == constant
        //avg case = O(min(length,breadth))
//
// Created by Akshaya's macbook on 2/20/26.
//
