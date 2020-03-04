/*
Complete the fumction numberOfPaths
The fumction takes integers 2D integer array, matrix, as parameter.
*/
int numberOfPaths(vector<vector<int>> matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
     
    vector<vector<int> > dp(m,vector<int>(n,0));
     
    if (matrix[0][0]!=1)
        return 0;
    dp[0][0]=1;
    for (int i=1;i<m;i++){
        if (matrix[i][0]!=0){
            dp[i][0] = dp[i-1][0];
        }
    }
    for (int i=1;i<n;i++){
        if (matrix[0][i]!=0){
            dp[0][i] = dp[0][i-1];
        }
    }
    for (int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if (matrix[i][j]!=0){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
    }   
    return dp[m-1][n-1];
}

