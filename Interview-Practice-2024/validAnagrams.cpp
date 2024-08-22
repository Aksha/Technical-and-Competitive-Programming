#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      //O(nmlogm) solution
        unordered_map<string, vector<string>> anagram_group;
        for(int i = 0; i < strs.size(); i++) { 
            string sorted_word = strs[i];
            sort(sorted_word.begin(), sorted_word.end());
            if(anagram_group.find(sorted_word) == anagram_group.end()) {
                vector<string> temp = {strs[i]};
                anagram_group.insert(make_pair(sorted_word, temp));
            }
            else {
                anagram_group[sorted_word].push_back(strs[i]);
            }
        }

        vector<vector<string>> result;
        for(auto it = anagram_group.begin(); it != anagram_group.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }

    vector<vector<string>> groupAnagramsByCount(vector<string>& strs) {
        //O(mn) solution
        unordered_map<int, vector<string>> anagram_group;
        for(auto s: strs) {
            int count = 0;
            for(char c: s) {
                count += c-'a';
            }
            if(anagram_group.find(count) == anagram_group.end()) {
                vector<string> temp = {s};
                anagram_group.insert(make_pair(count, temp));
            }
            else {
                anagram_group[count].push_back(s);
            }
        }
        vector<vector<string>> result;
        for(auto it = anagram_group.begin(); it != anagram_group.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }

};


int main() {
    Solution s;
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};
    vector<vector<string>> result = s.groupAnagramsByCount(strs);
    cout << "{";
    for(int i = 0; i < result.size(); i++) {
        cout << "{";
        for(int j = 0; j < result[i].size(); j++) {
            if(j == result[i].size() - 1) {
                cout << result[i][j];
            }
            else {
                cout << result[i][j] << ",";
            }
        }
        cout << "},";
    }
    cout << "}" << endl;
    return 0;
}
