/*
GIven a list of weights of people, can we form two groups of people in two different rooms respectively,
such that the combined weights of all the people in both rooms are the same?

Input: 
arr = {1,2,3,4,5,7}
output = True;
sum of the weights = 22;
room 1 people = {1,2,3,5} (weight = 11)
room 2 people = {4,7} (weight = 11)

*/

//Recursive Implementation: O(2^n) where n is the number of people

#include <iostream>
#include <vector>

using namespace std;

bool testfortie_helper (vector<int> arr, int i, int halfSum, bool result){
    if(halfSum == 0)
        return true;
    if(i == arr.size())
        return false;
    if(halfSum < 0)
        return false;
    else if(halfSum - arr[i] >= 0)
        result = testfortie_helper(arr,i+1, halfSum - arr[i], result);
    return result || testfortie_helper(arr, i+1, halfSum, result);
}

bool testfortie(vector<int> arr) {
    int sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    if(sum % 2 != 0)
        return false;
    int halfSum = sum/2;
    bool result = false;
    int i = 0;
    return testfortie_helper(arr,i, halfSum, result);
}

int main() {
    vector <int> arr = {56,2};
    if(arr.size() == 0 || arr.size() == 1)
        return false;
    bool result = testfortie(arr);
    cout << "The partition exists? :  " << result << endl;
    return 0;
}

//Dynamic Programming solution: O(n*halfSum) time and O(n*halfSum) space

#include <iostream>
#include <vector>

using namespace std;

bool testfortie(vector<int> arr, int halfSum) {
    int m = arr.size();
    int n = halfSum;
    vector<vector<bool>> dp(m+1,vector<bool>(n+1));
    for(int i = 0; i < m+1; i++) {
        dp[i][0] = true;
    }
    for(int i = 0; i <= halfSum; i++) {
        dp[m][i] = false;
    }
    for(int i = m-1; i >=0; i--){
        for(int j = 1; j <= halfSum; j++) {
            if( j - arr[i] >= 0)
                dp[i][j] = dp[i+1][j] || dp[i+1][j-arr[i]];
        }
    }
    return dp[0][halfSum];
}

int main() {
    vector <int> arr = {1,2,3,4,5,6,7};
    bool result;
    if(arr.size() == 0 || arr.size() == 1)
        result = false;
    int sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    if(sum % 2 != 0)
        result = false;
    int halfSum = sum/2;
    result = testfortie(arr, halfSum);
    cout << "The partition exists? :  " << result << endl;
    return 0;
}
