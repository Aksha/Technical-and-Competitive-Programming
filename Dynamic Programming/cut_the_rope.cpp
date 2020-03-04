Flawed solution:

/*
 * Complete the max_product_from_cut_pieces function below.
 */
long long int max_product_from_cut_pieces(int n) {
    /*
     * Write your code here.
     */
    int dp[n];
    long long int maxProduct = INT_MIN;
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; ++i) {
        int j = n - i;
        int currentProduct = i*j;
        if(currentProduct > dp[i-1]) 
            dp[i] = currentProduct;
        else 
            dp[i] = dp[i-1];
    }
    return dp[n];
}


