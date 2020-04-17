
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

