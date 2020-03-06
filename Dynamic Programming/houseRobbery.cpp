/* 
Robbery



Problem Statement:



There are n houses built in a line, each of which contains some value in it. A thief is going to steal the maximal value in these houses, but he cannot steal in two adjacent houses because the owner of a stolen house will tell his two neighbors on the left and right side. What is the maximal stolen value?



For example, if there are four houses with values [6, 1, 2, 7], the maximal stolen value is 13, when the first and fourth houses are stolen.



Input/Output Format For The Function:



Input Format:



You will be given an array of integer values, containing the value in each house.



Output Format:



Return an integer max, denoting the maximum possible robbery.

*/

// Complete the maxStolenValue function below.
int maxStolenValue(vector<int> values) {
        const int n = values.size();
        if (n == 0) return 0;
        if (n == 1) return values[0];
        if (n == 2) return max(values[0], values[1]);
        vector<int> f(n, 0);
        f[0] = values[0];
        f[1] = max(values[0], values[1]);
        for (int i = 2; i < n; ++i)
            f[i] = max(f[i-2] + values[i], f[i-1]);
        return f[n-1];

}
