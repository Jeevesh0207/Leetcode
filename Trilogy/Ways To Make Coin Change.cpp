// https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471

#include<bits/stdc++.h>

long countWaysToMakeChange(int *d, int n, int value) {
  vector<vector<long>> dp(n+1, vector<long>(value + 1, 0));
  for(int i=0;i<=value;i++){
    dp[0][i]=(i%d[0]==0);
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 1;
    for (int j = 0; j <= value; j++) {
      if (d[i] > j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j] + dp[i][j - d[i]];
    }
  }
  return dp[n][value];
}
