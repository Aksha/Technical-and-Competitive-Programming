//Paying attention to time complexity analysis from string_transformation_hint.png and combining solutions from 
//stringTransformation.cpp stringTransformation_better.cpp, I get the best and final solution that passes all test cases

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

bool isDiff1(string curr, unordered_set <string> hset, vector<string>& possibleWords) {
    int m = hset.size(); //cccw,accc,accw,cccc; curr = cccc
    if(m < 1)
        return false;
    int n = curr.size();
    for(unordered_set<string>::iterator it = hset.begin(); it != hset.end(); ++it) {
        int counter = 0;
        string temp = *it;
        for(int j = 0; j < n; j++) {
            if(curr[j] != temp[j])
                counter++;
        }
        if(counter == 1) {
            //cout << "Getting pushed in: " << temp << endl;
            possibleWords.push_back(temp); //possibleWords = cccw, accc
        }
    }
    if(possibleWords.size() >= 1) {
        return true;
    }
    return false;
}

void string_transformation_helper_2(unordered_set<string> hset,string start, string stop, vector<string>& result
) {
    queue<string> Q;
    Q.push(start); //cccc
    while (!Q.empty()) {
        string curr = Q.front(); //cccw
        Q.pop();
        vector<string> possibleWords;
        if (isDiff1(curr, hset, possibleWords) && hset.size() >= 1) {
            result.push_back(start);
            result.push_back(possibleWords[0]);
            result.push_back(stop);
            return;
        }
    }
}

void string_transformation_helper1(unordered_set<string> hset,string start, string stop,unordered_map<string,string>& parent,string& final) {
    queue<string> Q;
    Q.push(start);
    while(!Q.empty()) {
        string curr = Q.front();
        Q.pop();
        for(int i = 0; i < curr.size(); i++) {
            string temp = curr;
            for(char c = 'a'; c <= 'z'; c++) {
                temp[i] = c;
                if(hset.find(temp) != hset.end()) {
                    Q.push(temp); //Q = {bad,had}
                    parent.insert(make_pair(temp,curr)); //parent[cat] = bat; parent[hat] = bat; parent[bad] = bat; parent[had] = hat
                    hset.erase(temp); // hset = {}
                }
            }
        }
        if(curr == stop) {
            final = curr;
            break;
        }
    }
}

void string_transformation_helper3(unordered_set<string> hset,string start, string stop,unordered_map<string,string>& parent,string& final) {
    queue<string> Q;
    Q.push(start);
    while(!Q.empty()) {
        string curr = Q.front();
        Q.pop();
        vector<string>possibleWords;
        if(isDiff1(curr, hset, possibleWords) && hset.size() >= 1){ // if there exists a "word" in the "words" array that differs by just one character, return that word
            for(string word:possibleWords) {
                if(hset.find(word) != hset.end()) {
                    Q.push(word); //Q = {bad,had}
                    parent.insert(make_pair(word,curr)); //parent[cat] = bat; parent[hat] = bat; parent[bad] = bat; parent[had] = hat
                    hset.erase(word); // hset = {}
                }
            }
        }
        if(curr == stop) { //reason this comes at the end is for the sake of "case c"
            final = curr;
            break;
        }
    }
}


vector<string> string_transformation(vector<string> words, string start, string stop) {
    if(start == stop && words.size() == 0)
        return {"-1"};
    vector<string> result;
    unordered_map<string,string> parent;
    words.push_back(stop);
    unordered_set<string> hset(words.begin(), words.end());
    string final = "";
    int wSize = words.size();
    int wLength = 0;
    if(wSize >= 1)
        wLength = words[0].size();
    if(start != stop) {
        if(wSize <= wLength)
            string_transformation_helper1(hset, start, stop, parent, final);
        else
            string_transformation_helper3(hset, start, stop, parent, final);
        if(final.empty())
            return {"-1"}; //for one of the edge cases where if a path from source to destination doesn't exists
        while(!final.empty()) { //if a path exists, trace the path
            result.push_back(final);
            final = parent[final];
        }
        reverse(result.begin(), result.end());
    }
    else if(start == stop && hset.size() >= 1) {
        string_transformation_helper_2(hset, start, stop,result);
    }
    return result;
}
int main() {
    vector<string> words = {"cat","hat","bad","had"};
    string start = "bat";
    string stop = "had";
    vector<string> result = string_transformation(words, start, stop);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << ", ";
    return 0;
}
