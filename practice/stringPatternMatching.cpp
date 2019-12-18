
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// exact_match("apple", "ppl") == true
// exact_match("apple", "pxl") == false
// wildcard_match("apple", "p.l") == true
// wildcard_match("apple", "pple.") == false
// question_wildcard_match("apple", "pple.?") == true
// question_wildcard_match("apple", "px?y?z?p?le") == true
// question_wildcard_match("apple", "pple") == true

bool question_wildcard_match(string text,string pattern,int textIndex,int patternIndex) {
    if(textIndex >= text.size()) {
        if(patternIndex >= pattern.size()) {
            return true;
        }
        else {
            if(patternIndex+1 < pattern.size() && pattern[patternIndex+1] == '?') {
                return question_wildcard_match(text,pattern,textIndex,patternIndex+2);
            }
            else {
                return false;
            }
        }
    }
    else if(patternIndex >= pattern.size() && textIndex < text.size()) {
        return true;
    }
    else if(patternIndex+1 < pattern.size() && pattern[patternIndex+1] == '?') {
        if(pattern[patternIndex] == text[textIndex] || pattern[patternIndex] == '.') {
            return (question_wildcard_match(text,pattern,textIndex+1,patternIndex)) || (question_wildcard_match(text,pattern,textIndex,patternIndex+2));
        }
        else {
            return question_wildcard_match(text,pattern,textIndex,patternIndex+2);
        }
    }
    else {
        if(pattern[patternIndex] == text[textIndex] || pattern[patternIndex] == '.') {
            return question_wildcard_match(text,pattern,textIndex+1,patternIndex+1);
        }
        else {
            if(pattern[patternIndex] != text[textIndex]) {
                return question_wildcard_match(text,pattern,textIndex+1,patternIndex);
            }
            else {
                return false;
            }
        }
    }
}

int main() {
    string text = "apple";
    string pattern = "pxl"; // works for the following string combinations : "ppl","pple.?","pple",px?y?z?p?le.
    int textIndex = 0;
    int patternIndex = 0;
    bool result = question_wildcard_match(text,pattern,textIndex,patternIndex);

    if(result) {
        cout << " There is a wildcard match between the text and pattern: TRUE" << endl;
    }
    else {
        cout << "There is no match between the text and pattern: FALSE" << endl;
    }
    return 0;
}
