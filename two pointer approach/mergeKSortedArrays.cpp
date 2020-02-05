#include <iostream>
#include <vector>

using namespace std;

/*
 * Complete the mergeArrays function below.
 */
//merge method

vector<int> merge(vector<int> first, vector<int> second) {
    int i = 0;
    int j = 0;
    int m = first.size();
    int n = second.size();
    vector<int> result;
    while(i < m  && j < n) {
        if(first[i] < second[j]) {
            result.push_back(first[i]);
            i++;
        }
        else if (first[i] > second[j]) {
            result.push_back(second[j]);
            j++;
        }
        else {
            result.push_back(first[i]);
            i++;
            j++;
        }
    }
    while(i < m) {
        result.push_back(first[i]);
        i++;
    }
    while(j < n) {
        result.push_back(second[j]);
        j++;
    }
    return result;
}

vector<int> mergeArraysHelper(vector<vector<int>> &arr) {
    while(arr.size() > 1) {
        vector<int> first = arr[0];
        vector<int> second = arr[1];
        vector<int> result = merge(first,second);
        arr.push_back(result);
        arr.erase(arr.begin() + 0);
        arr.erase(arr.begin() + 0);
        mergeArraysHelper(arr);
    }
    return arr.front();
}
vector<int> mergeArrays(vector<vector<int>> arr) {
    return mergeArraysHelper(arr);
}



int main() {
    vector<vector<int>> arr = {{1, 3, 5, 7},
                               {2, 4, 6, 8},
                               {0, 9, 10, 11}};
    vector<int> result = mergeArrays(arr);
    int n = result.size();
    cout << "The merged array is : " << endl;
    for(int i = 0; i < n-1; i++) {
        cout << result[i] << ",";
    }
    cout << result[n-1] << endl;
    return 0;
}
