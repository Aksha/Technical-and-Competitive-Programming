//find the subsets from the given input that sum to the target. Input: {1,2,3} array, target: 3 int, output: {1,2}, {3} vector<vector<int>> two dimensional
//include/exclude technnique


#include<iostream>
#include<vector>

using namespace std;

void subsetSum(vector<int> &input, int target, int i, vector<vector<int>> &output, int curr_sum, vector<int> curr_set) {
    if(i <= input.size() && curr_sum == target) {
        output.push_back(curr_set);
        curr_set.clear();
        return;
    }
    if(i == input.size() || curr_sum > target) {
        return;
    }
    else {
        curr_set.push_back(input[i]);
        subsetSum(input, target, i + 1, output, curr_sum + input[i], curr_set);
        curr_set.pop_back();
        subsetSum(input, target, i + 1, output, curr_sum, curr_set);
    }
    return;
}

int main() {
    vector<int> input = {1,2,3};
    int target = 3;
    vector<vector<int>> output;
    vector<int> curr_set;
    subsetSum(input,target,0,output, 0, curr_set);
    for(auto o:output) {
        cout << "{";
        for(auto i : o) {
            cout << i << ",";
        }
        cout << "}" << endl;
    }
    return 0;
}
