/*
Count ways to reach the N’th stair



There are n stairs, a person standing at the bottom wants to reach the top. He can climb a certain number of steps at once. For instance, the person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top.

Solve the problem for the general case i.e. for n stairs, and different kinds of steps that can be taken (e.g. instead of only 1 or 2 steps, it could be 2, 3 and 5 steps at a time).



Example One

Input: n=1, steps=[1, 2]

Output: 1

Only one way to reach: [{1}]



Example Two

Input: n=2, steps=[1, 2]

Output: 2

Two ways to reach: [{1, 1}, {2}]


*/

long long int countWaysToClimb(vector<int> steps, int n) {
    vector<long long int> dp(n+1,0);
    dp[0] = 1;

    for (int i=1;i<=n;i++) {
        for(int j = 0; j < steps.size(); j++) {
            if(i >= steps[j])
                dp[i] = dp[i] + dp[i-steps[j]];
        }
    }
    return dp[n];
}

