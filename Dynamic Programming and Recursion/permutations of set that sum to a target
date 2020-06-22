#include <iostream>
#include <vector>

using namespace std;

void permutations(vector<int> arr,int target, int index, int & count, vector<int> temp, vector<vector<int>>& result) {
    if(target == 0) {
        count++;
        result.push_back(temp);
        temp.clear();
        return;
    }
    if (target < 0)
        return;
    for(int i = 0; i < arr.size(); i++) {
        if (target - arr[i] >= 0) {
            temp.push_back(arr[i]);
            permutations(arr, target - arr[i], index, count, temp,result);
            temp.pop_back();
        }
    }
    return;
}

int main() {
    vector<int> arr = {2, 3, 7};
    int target = 7;
    int count = 0;
    int index = 0;
    vector<int> temp;
    vector<vector<int>> result;
    permutations(arr, target, index, count, temp, result);
    cout << "The perumations are : " << endl;
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << "THE count of permutations : " << count << endl;
    return 0;
}
