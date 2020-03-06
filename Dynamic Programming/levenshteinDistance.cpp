/*
Levenshtein Distance



Problem Statement:



Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)



You have the following 3 operations permitted on a word:



a) Insert a character

b) Delete a character

c) Replace a character



The minimum no of steps required to convert word1 to word2 with the given set of allowed operations is called edit distance.



e.g. Minimum edit distance between the words 'kitten' and 'sitting', is 3.



kitten → sitten (substitution of "s" for "k")

sitten → sittin (substitution of "i" for "e")

sittin → sitting (insertion of "g" at the end)



Read more about edit distance here:

https://en.wikipedia.org/wiki/Edit_distance

*/


/*
 * Complete the function below.
 */
int min3(int a, int b, int c) {
    int minimum;
    
    minimum = min(a,b);
    return min(minimum, c);
} 
 
int levenshteinDistance(string s1, string s2) {
        
        if(s1.empty()) {
            return s2.length();
        }
        
        if(s2.empty()) {
            return s1.length();
        }
        
        int dp[s1.length()+1][s2.length()+1];
        
        for(int i=0; i <= s1.length(); i++) {
            dp[i][s2.length()] = s1.length()-i;
        }
        
        for(int j=0; j <= s2.length(); j++) {
            dp[s1.length()][j] = s2.length()-j;
        }
    
        for(int i=s1.length()-1; i >= 0; i--) {
            for(int j=s2.length()-1; j>=0; j--) {
                if(s1[i]==s2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = 1+min3(dp[i][j+1], dp[i+1][j+1], dp[i+1][j]);
                }
            }
        }
        
        return dp[0][0];

}
