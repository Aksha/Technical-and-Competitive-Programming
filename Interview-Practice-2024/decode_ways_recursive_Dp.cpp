#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/*
 * Input: s = "12"

Output: 2

Explanation:

"12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: s = "226"

Output: 3

Explanation:

"226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 * */

//This problem has both the recurisve solution and iterative solution (DP). DP is derived from the recurrence relationship here in this case from i+1 and i+2

void decodeWaysHelper(string input, string curr_word, vector<string> &result, int i, unordered_map<int, char> hmap){
    if(i >= input.size()) {
        result.push_back(curr_word);
        return;
    }
    int curr_num = input[i] - '0';
    if(curr_num != 0) {
        decodeWaysHelper(input, curr_word + hmap[curr_num], result, i+1, hmap);
    }
    if(i+1 < input.size()) {
        int next_num = input[i+1] - '0';
        int tot = curr_num*10 + next_num;
        if(hmap.find(tot) != hmap.end()) {
            decodeWaysHelper(input, curr_word + hmap[tot], result, i+2, hmap);
        }
    }
}



int decodeWaysRecursive1(string input) {
    if(input.empty()) {
        return 0;
    }
    unordered_map<int, char> hmap;
    int count = 1;
    for(char c = 'A'; c <= 'Z'; c++) {
        hmap[count] = c;
        count++;
    }
//    for(auto a : hmap) {
//        cout << a.first << ":" << a.second << endl;
//    }
    vector<string> result;
    decodeWaysHelper(input, "", result, 0, hmap);
    for(auto r : result) {
        cout << r << endl;
    }
    return result.size();
}

void decodeWaysHelper2(string input, int &result, int i, unordered_map<int, char> hmap){
    if(i >= input.size()) {
        result++;
        return;
    }
    int curr_num = input[i] - '0';
    if(curr_num != 0) {
        decodeWaysHelper2(input, result, i+1, hmap);
    }
    if(i+1 < input.size()) {
        int next_num = input[i+1] - '0';
        int tot = curr_num*10 + next_num;
        if(hmap.find(tot) != hmap.end()) {
            decodeWaysHelper2(input, result, i+2, hmap);
        }
    }
}

int decodeWaysIterative(string s){
    if (s.empty() || s[0] == '0') {
        return 0;
    }

    int n = s.length();
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        int oneDigit = s[i - 1] - '0';
        int twoDigits = stoi(s.substr(i - 2, 2));

        if (oneDigit != 0) {
            dp[i] += dp[i - 1];
        }

        if (10 <= twoDigits && twoDigits <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}

//only ways
//the way to decode first character if it isn't 0, is 1. else it is 0. 2nd character is a combination of how the first character is done + no of ways to decode this particular character.
int decodeWaysRecursive2(string input) {
    if(input.empty()) {
        return 0;
    }
    unordered_map<int, char> hmap;
    int count = 1;
    for(char c = 'A'; c <= 'Z'; c++) {
        hmap[count] = c;
        count++;
    }
    int result_count = 0;
    decodeWaysHelper2(input, result_count, 0, hmap);
    return result_count;
}

int main() {
    string input = "234";
    if(input[0] == '0') {
        cout << "The num of ways is : " << 0 << endl;
        return 0;
    }
    int result = decodeWaysRecursive1(input);
    cout << "the num of ways: " << result << endl;
    int recursive_result_twist = decodeWaysRecursive2(input);
    cout << "The number of ways for only numbers solution: " << recursive_result_twist << endl;
    return 0;
}
