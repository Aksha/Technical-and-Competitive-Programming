/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

1- none
2 - abc
3 - def
4 - ghi
5 - jkl
6 - mno
7 - pqrs
8 - tuv
9 - wxyz
0 - none

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/

//Solution:

vector<string> letterCombinations(string digits) 
    {
        vector<string> res;
        if(digits.size()==0) return res;
        string local;
        vector<vector<char>> table(2,vector<char>());
        table.push_back(vector<char>{'a','b','c'}); // index 2
        table.push_back(vector<char>{'d','e','f'}); // 3
        table.push_back(vector<char>{'g','h','i'});
        table.push_back(vector<char>{'j','k','l'}); // 5
        table.push_back(vector<char>{'m','n','o'});
        table.push_back(vector<char>{'p','q','r','s'}); // 7
        table.push_back(vector<char>{'t','u','v'});
        table.push_back(vector<char>{'w','x','y','z'}); // 9
        
        backtracking(table,res,local,0,digits);
        return res;
    }
    
    void backtracking(const vector<vector<char>>& table, vector<string>& res, string& local, int index, const string& digits) {
        if(index==digits.size())
            res.push_back(local);
        else
            for(int i=0;i<table[digits[index]-'0'].size();i++) {
                local.push_back(table[digits[index]-'0'][i]);
                backtracking(table, res, local, index+1, digits);
                local.pop_back();
            }
    }
