
O(n2^n) time and space.

#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > printAllSubsets(vector<int> arr)
{
    vector< vector<int> > subset;
    vector<int> empty;
    subset.push_back( empty );

    for (int i = 0; i < arr.size(); i++)
    {
        vector< vector<int> > subsetTemp = subset;

        for (int j = 0; j < subsetTemp.size(); j++)
            subsetTemp[j].push_back( arr[i] );

        for (int j = 0; j < subsetTemp.size(); j++)
            subset.push_back( subsetTemp[j] );
    }
    return subset;
}

int main() {
    vector<int> arr = {1,2,3};
    vector<vector<int>> subset = printAllSubsets(arr);
    for(int i = 0; i < subset.size(); i++) {
        for(int j = 0; j < subset[i].size(); j++) {
            cout << subset[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}

/*
Result:


1,
2,
1,2,
3,
1,3,
2,3,
1,2,3,

*/

//string based output:



//Combination problem:

//Time complexity: O(N.2^N)
//Space complexity: call stack O(N)

#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> printAllSubsets(vector<string> arr, int i, vector<vector<string>> subset) {
    if(i == arr.size())
        return subset;
    vector<vector<string>> subset_temp = subset;
    for(int j = 0; j < subset_temp.size(); j++) {
        subset_temp[j].push_back(arr[i]);
    }
    for(int j = 0; j < subset_temp.size(); j++)
        subset.push_back(subset_temp[j]);
    return printAllSubsets(arr,i+1,subset);

}


int main() {
    vector<string> arr = {"a", "b", "c"};
    vector<vector<string>> emptySubset;
    vector<string> empty;
    emptySubset.push_back(empty);
    int index = 0;
    vector<vector<string>> subset = printAllSubsets(arr, index, emptySubset);
    cout << "subset size : " << subset.size();
    for (int i = 0; i < subset.size(); i++) {
        for (int j = 0; j < subset[i].size(); j++) {
            cout << subset[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}

/*
Result:

subset size : 8
a,
b,
a,b,
c,
a,c,
b,c,
a,b,c,


*/
