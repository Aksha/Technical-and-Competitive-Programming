/*
Find All Well Formed Brackets



Problem Statement:



Given a positive integer n, find ALL well formed round brackets string of length 2*n.



The purpose of this problem is to learn recursion and not DP. So, you must write at least one recursive solution. After that, you can write a DP solution if you want.



Input/Output Format For The Function:



Input Format:



There is only one argument denoting integer n.



Output Format:



Return array of strings res, containing all possible well formed round brackets string. (Length of each string will be 2*n).



You need not to worry about the order of strings in res.

E.g. For n = 2, ["(())", "()()"] or ["()()", "(())"], both will be accepted.



Input/Output Format For The Custom Input:



Input Format:



There should be one line for input, containing an integer n.



If n = 3, then input should be:



3



Output Format:



Let’s denote the size of res is m, where res is the resultant array of string returned by the solution function.

Then, there will be m lines of output, where ith line contains res[i], denoting string at index i of res.



For input n = 3, output will be:



((()))

(()())

(())()

()(())

()()()



Constraints:



1 <= n <= 13
Only use round brackets. '(' and ')'.


Sample Test Case:



Sample Input:



3



Sample Output:



[

   "((()))",

   "(()())",

   "(())()",

   "()(())",

   "()()()"

]



(This is one of the possible outputs. Array containing these five string in any order, will be accepted.)
*/

void gp(string str,int l,int r, int &n, vector<string> &res){
    if (l>n){return;}
    if (l==n && r==n){
        res.push_back(str);
        return;
    }else{
        gp(str+"(",l+1,r,n,res);
        if (l>r){
            gp(str+")",l,r+1,n,res);
        }
    }
}

vector <string> find_all_well_formed_brackets(int n) {
    vector<string> res;
        if (n==0){return res;}
        gp("",0,0,n,res);
        return res;
}
