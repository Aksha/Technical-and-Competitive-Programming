#include <iostream>
#include <vector>

using namespace std;

bool equalSubSetSumPartition_helper(vector<int> &s,int i, int sum) {
    if(sum == 0) //base condition
        return true;
    if(i == s.size()) //base condition
        return false;
    bool result = false;
    if(sum >= s[i]) {
        result = equalSubSetSumPartition_helper(s,i+1,sum - s[i]) || equalSubSetSumPartition_helper(s,i+1,sum); //from the recursion tree
    }
    return result;
}

bool equalSubSetSumPartition(vector<int> &s) {
    int inputLength = s.size();
    int sum = 0;
    for(int i = 0; i < inputLength; i++) {
        sum += s[i];
    }
    if(sum%2 != 0)
        return {};

    int halfSum = sum/2;
    int i = 0;
    return equalSubSetSumPartition_helper(s,i,halfSum);
}

int main() {
    vector <int> arr = {1,2,3,4,5,7};
    bool result = equalSubSetSumPartition(arr);
    cout << "the result is : " << result << endl;
    return 0;
}
