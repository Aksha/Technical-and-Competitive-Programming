/*

Find the minimum Number of coins as change to meet target. 

1. Optimization problem or counting problem . This case - optimization (minimum no of coins to reach a target sum)
2. Recurrence equation. 
for every sum from 1 to target :
  for every coin : 
    T[i] = min(sum - arr[each_coin])
3. Identify all possible subproblems (all sums from 0 to target)
4. Identify possible dependencies?
5. Identify DS for DP table of size coin from 0 to target
6. Initialize DP table : table[0] = 0.
7. Identify direction of DS  -> rightwards --> 0,1,2,3,4
8. Populate DP table.
*/

//DP solution

int coinChange( vector<int> coins,int target) {
  vector<int> table(target+1,INT_MAX);
  table[0] = 0;

  for(int i = 1; i <= target; i++) {
    for(int j = 0; j < coins.size();j++) {
      if(i - coins[j] >= 0) {
        table[i] = min(table[i], table[i-coins[j]]) + 1;
      }
    }
  }
  return table[target];
}
