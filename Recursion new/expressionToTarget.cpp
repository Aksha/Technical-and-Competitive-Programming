
/*
 * Generate All Possible Expressions That Evaluate To The Given Target Value



Given a string s that consists of digits (“0”..”9”) and target, a non-negative integer, find all expressions that can be built from string s that evaluate to the target.

When building expressions, you have to insert one of the following operators between each pair of consecutive characters in s: “join” or “*” or “+”. For example, by inserting different operators between the two characters of string “12” we can get either 12 (1 joined with 2) or 2 (1*2) or 3 (1+2).

Other operators such as “-” or “÷” are NOT supported.

Expressions that evaluate to the target but only utilize a part of s do not count: entire s has to be consumed.

Precedence of the operators is conventional: “join” has the highest precedence, “*” – medium and “+” has the lowest precedence. For example, 1+2*34=(1+(2*(34)))=1+68=69.

You have to return ALL expressions that can be built from string s and evaluate to the target.



Example One

Input:

s="222", target=24.



Output:

["22+2", "2+22"] and ["2+22", "22+2"] are both correct outputs.

22+2=24: we inserted the “join” operator between the first two characters and the “+” operator between the last two characters of s.
2+22=24: we inserted the “+” operator between the first two characters and the “join” operator between the last two characters of s.


Example Two

Input: s="1234", target=11.



Output: ["1+2*3+4"]



Example Three

Input:

s="99", target=1.



Output:

[]


 */
 
long long int calculateValue(string str) {
    long long int value = 0;
    stack <long long int> s;
    int m = str.size();
    int i = 0;
    while(i < m) {
        if(str[i] == '*') {
            long long int num1 = s.top();
            s.pop();
            i++;
            long long int num2 = str[i];
            long long int prod = num1*num2;
            s.push(prod);
        }
        else {
            s.push(str[i]);
        }
        i++;
    }
    long long int num1 = 0;
    long long int num2 = 0;
    while(!s.empty) {
        //if num , check if num1 variable is empty, if yes, assign num1 = s.top(), else multiple*10 and add with s.top() and assign it to num1.
        //if +, add num1 value and pop, top the next num2.
        if(s.top() != '+') {
            if(num1 != 0) 
                num1 = num1*10 + s.top();
            else 
                num1 = s.top();
            s.pop();
        }
        else {
            s.pop();
            while(s.top() != '+') {
                if(num1 != 0) 
                    num1 = num1*10 + s.top();
                else 
                    num1 = s.top();
                s.pop();
            }
            value = num1 + num2;
        }
    }
    return value;
}



//helper method should have variables "index" position and "stringSoFar" 
//3 recursive calls about insert '+', '*' and concat at the right index position
//base case: stop when end is reached and calculate the value here. If currValue == target, push the respective string into result variable of type vector<string>.
void generate_all_expressions_helper(string s,long long int target,int index, string stringSoFar, int n, vector<string>& result) {
    if(index == n){
        long long int currVal = calculateValue(stringSoFar);
        if(currVal == target) 
            result.push_back(stringSoFar);
        return;
    }
    for(int i = index; i < s.length(); i++) {
        generate_all_expressions_helper(s,target,index+1,stringSoFar + "+" + s.substr(index,i-index+1), n, result);
        generate_all_expressions_helper(s,target,index+1,stringSoFar + "*" + s.substr(index,i-index+1), n, result);
    }
    return;   
}

vector <string> generate_all_expressions(string s, long long int target) {
    vector<string> result;
    int index = 0;
    string stringSoFar = "";
    int n = s.size();
    generate_all_expressions_helper(s,target,index,stringSoFar,n, result);
    return result;
}

//Better way:

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

//All expressions that sum to the target value
/*
* Input:
s="222", target=24.
Output:

["22+2", "2+22"] and ["2+22", "22+2"] are both correct outputs.

22+2=24: we inserted the “join” operator between the first two characters and the “+” operator between the last two characters of s.
2+22=24: we inserted the “+” operator between the first two characters and the “join” operator between the last two characters of s.

 This problem has two parts.. Getting the expressions string and then calculating its value to check if evaluates to the target.
 * */

void generate_all_expressions_helper(string s, int index, string stringSoFar, vector<string>& result, int n) {
    if(index == n) {
        result.push_back(stringSoFar);
        return;
    }
    generate_all_expressions_helper(s,index+1,stringSoFar + "+" + s[index], result, n);
    generate_all_expressions_helper(s,index+1,stringSoFar + "*" + s[index], result, n);
    generate_all_expressions_helper(s,index+1,stringSoFar + "|" + s[index], result, n);
    return;
}

vector<string> generate_all_expressions(string s) {
    int index = 1;
    vector<string> result; // collects all strings
    string stringSoFar = "";
    stringSoFar += s[0];
    int n = s.length();
    generate_all_expressions_helper(s,index,stringSoFar,result,n);
    return result;
}

int calcVal(string s) {
    bool mul = 0;
    bool add = 0;
    bool concat = 0;
    int i = 0;
    int n = s.size();
    int num = 0;
    int value = 0;
    while(i < n) {
        if(s[i] == '+')
            add = 1;
        else if(s[i] == '*')
            mul = 1;
        else if(s[i] == '|')
            num = num * 10 + (s[i] - '0');
        else if(add == 1) {
            int temp = 0;
            while(s[i] != '+' && s[i] != '*') {
                if(temp == 0) {
                    temp = (s[i]-'0');
                }
                else {
                    temp = temp*10 + (s[i] - '0');
                }
                i++;
            }
            value += num + temp;
            num = 0;
            add = 0;
        }
        else if(mul != 0) {
            int temp = 0;
            while(s[i] != '+' && s[i] != '*') {
                if(temp == 0) {
                    temp = (s[i]-'0');
                }
                else {
                    temp = temp*10 + (s[i] - '0');
                }
                i++;
            }
            value += num * temp;
            num = 0;
            mul = 0;
        }
        else
            num = s[i];
        i++;
    }
    return value;
}

int main() {
    string s = "222";
    long long int target = 24;
    vector<string> expressions = generate_all_expressions(s);
    cout << "Printing the generated strings: " << endl;
    int n = expressions.size();
    vector<string> result;
    for(int i = 0; i < n; i++) {
        int value = calcVal(expressions[i]);
        if(value == target) {
            result.push_back(expressions[i]);
        }
    }
    //calculate values at this point
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}


//Discard existing solution... Making progress.. Have trouble getting concatenation right

/*
 * Complete the function below.
 */
 


//helper method should have variables "index" position and "stringSoFar" 
//3 recursive calls about insert '+', '*' and concat at the right index position
//base case: stop when end is reached and calculate the value here. If currValue == target, push the respective string into result variable of type vector<string>.
void generate_all_expressions_helper(string s, int index, string stringSoFar, vector<string>& result, int n, int target, int currValue, int last) {
    if(index == n) {
        if(currValue == target) {
            result.push_back(stringSoFar);
        }
        //result.push_back(stringSoFar);
        //values.push_back(currValue);
        return;
    }
    if (index == 0) {
        string temp = "";
        generate_all_expressions_helper(s, index + 1, temp + s[index], result, n, target,(s[index] - '0'), (s[index] - '0'));
    }
    else {
        generate_all_expressions_helper(s, index + 1, stringSoFar + "+" + s[index], result, n, target,
                                        currValue + (s[index] - '0'), (s[index] - '0'));
        generate_all_expressions_helper(s, index + 1, stringSoFar + "*" + s[index], result, n, target,
                                        currValue - last + (last * (s[index] - '0')),
                                        last * (s[index] - '0'));
        generate_all_expressions_helper(s, index + 1, stringSoFar + s[index], result, n, target,
                                        currValue * 10 + (s[index] - '0'), (s[index] - '0'));
    }
    return;
}

vector<string> generate_all_expressions(string s, int target) {
    int index = 0;
    vector<string> result; // collects all strings
    string stringSoFar = "";
    int n = s.length();
    generate_all_expressions_helper(s,index,stringSoFar,result,n, target,0,0);
    return result;
}

