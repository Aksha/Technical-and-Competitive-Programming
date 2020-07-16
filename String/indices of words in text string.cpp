/*
Indices Of Words In Text String
Given some text and a bunch of words, find where each of the words appear in the text. Text may contain spaces, words may not.
For every given word you need to return a list of (zero-based) indices of where that word starts in the text. If a word isn’t found in the text, return [-1] for that word.
Example
Input:
text = “you are very very smart”
words = [“you”, “are”, “very”, “handsome”]

Output:

[ [0], [4], [8, 13], [-1] ]

“you” is found in the given text starting at the index 0.

“are” is found in the given text starting at the index 4.

“very” is found in the given text two times, starting at the indices 8 and 13.

“handsome” isn’t found in the given text.
Notes
Input Parameters:
Function has two arguments: string text and list of strings words.
Output: Function must return a list of lists of integers. One list for each one of the words. i-th list must contain all indices of characters in text where i-th word starts, in the ascending order. If i-th word isn’t found in the text at all, then i-th list must be [-1].
*/

//Verbose solution: 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
#include <istream>
#include <unordered_set>

using namespace std;

/*
 * text = “you are very very smart”
words = [“you”, “are”, “very”, “handsome”]
 */

vector<vector<int>> find_starting_indices(vector <string> words, string text) {
    vector<vector<int>> result;
    unordered_set<string> arr;
    for(int i = 0; i < words.size(); i++) {
        arr.insert(words[i]);
    }
    istringstream sentence(text);
    string word;
    int i = 0;
    unordered_map<string,vector<int>> word_index;
    while(getline(sentence,word,' ')) {
        //cout << "word: " << word << "; index : " << i << endl;
        if(word_index.find(word) == word_index.end()) {
            vector<int> temp;
            temp.push_back(i);
            word_index.insert(make_pair(word,temp));
        }
        else {
            word_index[word].push_back(i);
        }
        i = i + word.size() + 1;
    }
    /*for(auto it : word_index) {
        cout << it.first << " : ";
        for(int i = 0 ; i < it.second.size(); i++) {
            cout << it.second[i] << " ";
        }
        cout << endl;
    } */
    for(unordered_set<string>::iterator it = arr.begin(); it != arr.end(); it++) {
        vector<int> temp;
        if(word_index.find(*it) != word_index.end()){
            temp = word_index[*it];
        }
        else {
            temp = {-1};
        }
        result.push_back(temp);
    }
    return result;
}
int main() {
    string text = "you are very very smart";
    vector <string> words = {"you", "are", "very","handsome"};
    vector<vector<int>> indices = find_starting_indices(words,text);
    for(int i = 0; i < indices.size();i++) {
        cout << "[";
        for(int j = 0; j < indices[i].size(); j++) {
            cout << indices[i][j] << " ";
        }
        cout << "] ";
    }
    return 0;
}


//Non - verbose solution: 
vector<vector<int>> find_words(string text, vector<string> words) 
    vector<vector<int>> ans;
    unordered_map<string, vector<int>> map;    
    int start = 0, i = 0;
    for (i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            map[text.substr(start, i-start)].push_back(start);
            start = i+1;
        }
    }
    map[text.substr(start, i-start)].push_back(start);    
    for (auto word : words) {
        if (map.find(word) != map.end())
            ans.push_back(map[word]);
        else
            ans.push_back({-1});
    }
    return ans;
}
