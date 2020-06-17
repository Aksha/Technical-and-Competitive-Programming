/*
Longest Common Subsequence

Find the longest common subsequence of two strings.
A subsequence is a sequence that can be derived from another sequence by deleting zero or more elements without changing the order of the remaining elements.

Example
Input: “ABCDE”, “AECBD”
Output: “ABD”
Subsequence “ABD” can be derived from the first string by deleting characters “C” and “E”. From the second string it can be derived by deleting “E” and “C”. No common subsequence longer than three characters exists in the two given strings. “ACD” is another common subsequence of length three; it is also a correct answer.

Notes

Input Parameters: The function has two string parameters.
Output: Return a string, the longest common subsequence. If a nonempty common subsequence cannot be found, return “-1”.
*/

#include <iostream>
#include <vector>

using namespace std;

string lcs(string a, string b) {
    int m=a.length();
    int n=b.length();

    //initialize dp table
    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for(int i = 0; i < m; i++) {
        dp[m][0] = 0;
    }

    for(int i = 0; i < n; i++) {
        dp[0][n] = 0;
    }
    /*for(int i = 0; i < m+1; i++) {

    }*/
    for(int i = 1; i < m+1; i++) {
        for(int j = 1; j < n+1; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    if(dp[m][n] == 0) {
        return "-1";
    }

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    //trace the string backward.
    string res = "";

    int r = dp.size()-1;
    int c = dp[0].size()-1;

    for(int i = r, j = c;i >= 0 && j >= 0;) {
        if(a[i-1] == b[j-1]){
            res = res + a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    reverse(res.begin(),res.end());

    return !res.empty() ? res : "-1";
}

int main() {
    string a = "ABCDE";
    string b = "AECBD";
    string result = lcs(a,b);
    cout << "The longest common subsequence is : " << result << endl;
    return 0;
}
