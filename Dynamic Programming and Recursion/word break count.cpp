/*
Word Break Count
Given a dictionary of words and a string, find the number of ways the string can be broken down into the dictionary words. Return the answer modulo 10^9 + 7.

Example
Input: Dictionary: [“kick", "start", "kickstart", "is", "awe", "some", "awesome”]. String: “kickstartisawesome”.
Output: 4

Here are all four ways to break down the string into the dictionary words:

kick start is awe some
kick start is awesome
kickstart is awe some
kickstart is awesome

*/


#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

//wrong implementation : 
bool word_break_count(string S, unordered_set<string> dict, int &count) {
    int size = S.size();

    // Base case
    if (size == 0)  {
        return true;
    }

    for (int i = 1; i <= size; i++)
    {
        if ((dict.find( S.substr(0, i)) != dict.end())) {
            word_break_count(S.substr(i, size-i), dict, count);
            count++;
            return true;
        }
    }

    // If we have tried all prefixes and
    // none of them worked
    return false;
}

//Right Implementation
void word_break_count_recursion(string S, unordered_set<string> dict, int &count, int start, int end) {
    if(start == end) {
        count++;
        return;
    }
    for(int i = 0; i < end-start; i++) {
        string temp = S.substr(start,i+1);
        if(dict.find(temp) != dict.end()) {
            word_break_count_recursion(S, dict, count,start+i+1,end);
        }
    }
}


int main() {
    string S = "kickstartisawesome";
    unordered_set<string> dict = {"kick","start", "kickstart", "is", "awe", "some", "awesome"};
    int count = 0;
    word_break_count(S,dict,count);
    cout << "The number of sentences with word breaks : " << count << endl;
    int count1 = 0;
    word_break_count_recursion(S,dict,count1,0,S.size());
    cout << " The number of sentences with word breaks with my method : " << count1 << endl;
    return 0;
}

//Dynamic Programming Solution:

long long MOD = 1e9 + 7;

int dp_helper(unordered_set<string> & string_hash, string & txt, long long int i) {

    long long int n = txt.size();

    vector<long long int> DP(n+1);

    DP[n] = 1;

    for(long long int i = n -1; i >= 0; --i) {
        long long int result = 0;

        string segment = "";
        
        for(long long int index = i ; index < txt.size(); ++index) {
            segment.push_back(txt[index]);
            if(string_hash.find(segment) != string_hash.end()) {
                result += DP[index+1];
                result %= MOD;
            }
        }
        
        DP[i] = result;
    }
    return DP[0];
}

int wordBreakCount(vector<string> &dictionary, string &txt)
{
    unordered_set<string> string_hash;
    long long int n = dictionary.size();

    for(long long int i = 0; i < n; ++i) {
        string_hash.insert(dictionary[i]);
    }

    return dp_helper(string_hash, txt, 0);
}




