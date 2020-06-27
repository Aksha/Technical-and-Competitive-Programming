#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int knights_tour_iteration(int start_number, int digits, unordered_map<int,vector<int>> hmap) {
    vector<vector<int>> dp(10, vector<int> (digits+1, 0));
    for (int i = 0; i <= 9; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for(int j = 2; j < digits+1; j++) {
        for(int i = 0; i <= 9; i++) {
            for(vector<int>::iterator it = hmap[i].begin(); it != hmap[i].end(); it++) {
                dp[i][j] += dp[*it][j-1];
            }
        }
    }
    return dp[start_number][digits];
}

void knights_tour_recursion(int start_number,int digits, unordered_map<int,vector<int>> hmap, int index, int &result) {
    if(index == digits-1) {
        cout << "The index is : " << index << "; start number is : " << start_number << endl;
        result++;
        return;
    }
    if(hmap.find(start_number) != hmap.end()) {
        for(auto a : hmap[start_number]) {
            knights_tour_recursion(a,digits,hmap,index+1,result);
        }
    }
    return;
}


int main() {
    int start_number =1;
    int digits = 3;
    unordered_map<int,vector<int>> hmap;
    vector<int> temp = {6,8};
    hmap.insert(make_pair(1,temp));
    temp = {7,9};
    hmap.insert(make_pair(2,temp));
    temp = {8,4};
    hmap.insert(make_pair(3,temp));
    temp = {3,9,0};
    hmap.insert(make_pair(4,temp));
    temp = {};
    hmap.insert(make_pair(5,temp));
    temp = {1,7,0};
    hmap.insert(make_pair(6,temp));
    temp = {2,6};
    hmap.insert(make_pair(7,temp));
    temp = {1,3};
    hmap.insert(make_pair(8,temp));
    temp = {2,4};
    hmap.insert(make_pair(9,temp));
    temp = {4,6};
    hmap.insert(make_pair(0,temp));
    int index = 0;
    int result = 0;
    knights_tour_recursion(start_number,digits, hmap, index, result);
    cout << "the count of different numbers using recursion : " << result << endl;
    int count = knights_tour_iteration(start_number,digits, hmap);
    std::cout << "The count of different numbers using iteration: " << count << std::endl;
    return 0;
}
