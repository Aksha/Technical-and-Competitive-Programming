/*
Recursive solution format: if the person can do 1 step, 2 steps or 3 steps at a time.

public :int findStep(int n) 
{ 
    if (n == 1 || n == 0)  
        return 1; 
    else if (n == 2)  
        return 2; 
      
    else
        return findStep(n - 3) +  
            findStep(n - 2) + 
            findStep(n - 1);  
} 
}; 

Extending to our more general question here:

Q. Count Ways To Reach The Nth Stairs

There are n stairs, a person standing at the bottom wants to reach the top. He can climb a certain number of steps at once. For instance, the person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top.
Note: Solve the problem for general case i.e. for n stairs, and different kinds of steps that can be taken (e.g. instead of only 1 or 2 steps, it could be 2, 3 and 5 steps at a time).
Input/Output Format For The Function:
Input Format:
There will be two arguments: steps and n.
An array of integer steps of size m denotes the steps the person can climb at a time and an integer n denotes the total number of stairs to be climbed.
Note: Answer is guaranteed to fit in long integer.
Output Format:
Return an integer ways, denoting the number of ways to reach the last staircase.
Input/Output Format For The Custom Input:
Input Format:
The first line should contain m (let say), denoting size of steps array. In next m lines, ith line should contain steps[i], denoting ith value in array steps. In the next line, there should be an integer, denoting n.

If n = 7 and steps = [2, 3], then input should be:
2
2
3
7

Output Format:
There will be one line, containing an integer ways, denoting the number of ways to reach the last staircase.
For input n = 7 and steps = [2, 3], output will be:
3
*/

// Wrong Complete the countWaysToClimb function below. What is wrong? Do you know?
long long int countWaysToClimb(vector<int> steps, int n) {
    long long int res[n + 1]; 
    res[0] = 1; 
    res[1] = 1; 
    res[2] = 2; 
    long long int m = steps.size();
    for (long long int i = 3; i <= n; i++)  {
        for(long long int j = 0; j < m; j++) {
            res[i] += res[i- steps[j]];
        }
    }
    return res[n]; 
}

//Right Solution:
long long int countWaysToClimb(vector<int> steps, int n) {
    vector<long long int> dp(n+1,0);
    dp[0]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<steps.size();j++)
        {
            dp[i]+=(i>=steps[j])?dp[i-steps[j]]:0;
        }
    }
    
    return dp[n];
}
