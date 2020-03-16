/*416. Partition Equal Subset Sum

Share
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false
*/

//Solution:

#include <iostream>
#include <vector>

using namespace std;

/*
 * Complete the equalSubSetSumPartition function below.
 *
 * @param s : input array as parameter.
 */

//Partial solution solved in class. Suggest brute force

bool equalSubSetSumPartition(vector<int> &s)
{
    int inputLength = s.size();
    int sum = 0;
    for(int i = 0; i < inputLength; i++) {
        sum += s[i];
    }
    if(sum%2 != 0)
        return {};

    int halfSum = sum/2;
    vector<vector<bool>> dp(inputLength+1,vector<bool>(halfSum+1));

    for(int i = 0; i <= inputLength;i++)
        dp[i][0] = true;

    for(int currSum = 1; currSum <= halfSum; ++currSum)
        dp[inputLength][currSum] = false;

    for(int i = inputLength - 1; i >= 0; --i) {
        for(int currSum = 1; currSum <= halfSum; ++currSum) {
            if(currSum >= s[i])
                dp[i][currSum] = dp[i+1][currSum - s[i]] || dp[i+1][currSum];
            else {
                cout << "do I come here : " << endl;
                dp[i][currSum] = false;
            }
        }
    }
    return dp[0][halfSum];
}



int main() {
    vector <int> arr = {3,1};
    bool result = equalSubSetSumPartition(arr);
    cout << "the result is : " << result << endl;
    return 0;
}

//Leetcode solution:
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int half = sum >> 1;
        
        vector<bool> accessibility(half + 1, false);
        accessibility[0] = true;    // '0' is always reachable
        //For all num in nums, check the accessibility from half - num to 0. 
        //If 'i' is accessible by former numbers, then 'i + num' is also accessible. (DP Algorithm)
        for(auto num : nums) 
       //Below here we must start from 'half' downto 'num', otherwise current 'num' might be multiply used. 
       //e.g.: If num == 2, then we will have 2, 4, 6... will all be accessible and lead to wrong answer. 
            for(int i = half; i >= num; i--){
                if (accessibility[i - num] == true){
                    accessibility[i] = true;
                }
            }
        return accessibility[half];
    }
};
