#include <iostream>
#include <vector>

using namespace std;
/*
 *  S = "banana"
 *  output : ana
 *   banan
 *   bana
 *   ban
 *   ba
 *   b
 *   anana
 *   anan
 *   ana
 *   an
 *   a
 *
 *
 *   now all of these are prefixes of the following strings of varying lengths starting in the beginning
 *
 *   banana - 0
 *   anana  - 1
 *   nana   - 2
 *   ana    - 3
 *   na     - 4
 *   a      - 5
 
 a        - 5 
 ana      - 3
 anana    - 1
 banana   - 0
 na       - 4
 nana     - 2
 *
 *
 * */

int compare_string(string a, string b) {
    int n = a.size();
    int m = b.size();
    int size = min(n,m);
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(a[i] != b[i]) {
            return count;
        }
        else {
            count++;
        }
    }
    return count;
}

string longest_repeated_substring(string s) {
    int n = s.size()-1;
    if(n == 0 || n == 1) {
        return s;
    }
    if(n == 2) {
        if(s[0] == s[1]) {
            string result = "";
            result += s[0];
            return result;
        }
        else {
            return "";
        }
    }
    vector<string> substring_list;
    for(int i = 0; i <= n; i++) {
        string temp = s.substr(i, n - i + 1);
        substring_list.emplace_back(temp);
    }
    sort(substring_list.begin(), substring_list.end());
    int maximum = INT_MIN;
    string output = "";
    for(int i = 0; i < substring_list.size()-1; i++) {
        int comparison = compare_string(substring_list[i], substring_list[i+1]);
        if( comparison > maximum) {
            maximum = comparison;
            output = substring_list[i].substr(0,comparison);
        }
    }
    return output;
}

int main() {
    string s = "banana";
    string output  = longest_repeated_substring(s);
    cout << "the longest repeated substring is : " << output << endl;
    return 0;
}
