//Flawed solution:

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

//Analyze ^^ why because it is considering only a product of two numbers. The rope could be cut into more pieces.

/*
 * Complete the max_product_from_cut_pieces function below.
 */
long long int max_product_from_cut_pieces(int n) {
    /*
     * Write your code here.
     */
    long long int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(long long int i = 2; i <= n; ++i) {
        long long int maxProduct = LLONG_MIN;
        for(long long int j = 1; j <= i/2; ++j) {
            long long int tempMax = max((i-j)*j, j*dp[i-j]);
            maxProduct = max(maxProduct, tempMax); 
        }
        dp[i] = maxProduct; 
    }
    return dp[n];
}



