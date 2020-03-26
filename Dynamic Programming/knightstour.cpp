/*   Knight's tour!
Given a phone keypad as shown below:

1 2 3
4 5 6
7 8 9

– 0 –

How many different phone numbers of given length can be formed starting from the given digit? The constraint is that the movement from one digit to the next is similar to the movement of the Knight in chess.
For example if we are at 1 then the next digit can be either 6 or 8, if we are at 6 then the next digit can be 1, 7 or 0.
Repetition of digits is allowed, e.g. 1616161616 is a valid number.
The problem requires us to just give the count of different phone numbers and not necessarily list the numbers.
Find a polynomial-time solution, based on Dynamic Programming.

Example One

Input: startdigit = 1, phonenumberlength = 2
Output: 2
Two possible numbers of length 2: 16, 18.

Example Two

Input: startdigit = 1, phonenumberlength = 3
Output: 5
The possible numbers of length 3: 160, 161, 167, 181, 183

*/

//Solution:


/*
 * Complete the function below.
 */
long long int numPhoneNumbers(int startdigit, int phonenumberlength) {
    unordered_map<int, vector<int>> pre;
    int n = phonenumberlength;
    pre[0] = {4, 6};
    pre[1] = {6, 8};
    pre[2] = {7, 9};
    pre[3] = {4, 8};
    pre[4] = {3, 9, 0};
    pre[5] = {};
    pre[6] = {1, 7, 0};
    pre[7] = {2, 6};
    pre[8] = {1, 3};
    pre[9] = {2, 4};
    vector<vector<long long int>> dp(10, vector<long long int> (n+1, 0));
 
    for (int i = 0; i <= 9; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    int d = startdigit;
    for (int j = 2; j < n+1; j++)
        for (int i = 0; i <= 9; i++)
            for (auto u : pre[i]) 
                dp[i][j] += dp[u][j-1];

    return dp[startdigit][n];
}

//Recursive solution and another DP solution:


/*
 * Complete the function below.
 */

long long int numPhoneNumbersHelper(int startdigit, int phonenumberlength) {
    if(phonenumberlength == 1) return 1;
    
    if(startdigit == 0) 
        return (numPhoneNumbersHelper(4, phonenumberlength-1) + numPhoneNumbersHelper(6, phonenumberlength-1));
    
    if(startdigit == 1)
        return (numPhoneNumbersHelper(6, phonenumberlength-1) + numPhoneNumbersHelper(8, phonenumberlength-1));
        
    if(startdigit == 2) 
        return (numPhoneNumbersHelper(7, phonenumberlength-1) + numPhoneNumbersHelper(9, phonenumberlength-1));
        
    if(startdigit == 3) 
        return (numPhoneNumbersHelper(4, phonenumberlength-1) + numPhoneNumbersHelper(8, phonenumberlength-1));
    
    if(startdigit == 4) 
        return (numPhoneNumbersHelper(3, phonenumberlength-1) + numPhoneNumbersHelper(9, phonenumberlength-1)
        + numPhoneNumbersHelper(0, phonenumberlength-1));
        
    if(startdigit == 5) return 0;
    
    if(startdigit == 6) 
        return (numPhoneNumbersHelper(1, phonenumberlength-1) + numPhoneNumbersHelper(7, phonenumberlength-1)
        + numPhoneNumbersHelper(0, phonenumberlength-1));
    
    if(startdigit == 7) 
        return (numPhoneNumbersHelper(2, phonenumberlength-1) + numPhoneNumbersHelper(6, phonenumberlength-1));
        
    if(startdigit == 8) 
        return (numPhoneNumbersHelper(1, phonenumberlength-1) + numPhoneNumbersHelper(3, phonenumberlength-1));
    
    if(startdigit == 9) 
        return (numPhoneNumbersHelper(2, phonenumberlength-1) + numPhoneNumbersHelper(4, phonenumberlength-1));
        
    return 0;
}
 
long long int numPhoneNumbers(int startdigit, int phonenumberlength) {
    //return numPhoneNumbersHelperRec(startdigit, phonenumberlength);
    long long int table[phonenumberlength+1][10] = {0};
    for(int i = 0; i  < 10; i ++) {
        table[0][i] = 0;
        //table[5][i] = 0;
        table[1][i] = 1;
    }
    
    for(int i = 2; i <= phonenumberlength; i++) {
        for(int j = 0; j < 10; j++) {
            if(j == 0) table[i][j] = table[i-1][4] + table[i-1][6];
            if(j == 1) table[i][j] = table[i-1][6] + table[i-1][8];
            if(j == 2) table[i][j] = table[i-1][7] + table[i-1][9];
            if(j == 3) table[i][j] = table[i-1][4] + table[i-1][8];
            if(j == 4) table[i][j] = table[i-1][3] + table[i-1][9] + table[i-1][0];
            if(j == 5) table[i][j] = 0;
            if(j == 6) table[i][j] = table[i-1][1] + table[i-1][7] + table[i-1][0];
            if(j == 7) table[i][j] = table[i-1][2] + table[i-1][6];
            if(j == 8) table[i][j] = table[i-1][1] + table[i-1][3];
            if(j == 9) table[i][j] = table[i-1][2] + table[i-1][4];
        }
    }
    
    return table[phonenumberlength] [startdigit];
}

