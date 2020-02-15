//Combination problem:

Time complexity: O(N.2^N)
Space complexity: call stack O(N)
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> printAllSubsets(vector<int> arr, int i, vector<vector<int>> subset) {
    if(i == arr.size())
        return subset;
    vector<vector<int>> subset_temp = subset;
    for(int j = 0; j < subset_temp.size(); j++)
        subset_temp[j].push_back(arr[i]);
    for(int j = 0; j < subset_temp.size(); j++)
        subset.push_back(subset_temp[j]);
    return printAllSubsets(arr,i+1,subset);

}


int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> emptySubset;
    vector<int> empty;
    emptySubset.push_back(empty);
    int index = 0;
    vector<vector<int>> subset = printAllSubsets(arr, index, emptySubset);
    cout << "subset size : " << subset.size();
    for (int i = 0; i < subset.size(); i++) {
        for (int j = 0; j < subset[i].size(); j++) {
            cout << subset[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
