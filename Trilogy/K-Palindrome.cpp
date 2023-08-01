//https://www.codingninjas.com/studio/problems/k-palindrome_2434296?

bool isPalindrome(int k, string str) {
  int n = str.size();
  int dp[n + 1][n + 1];
  string s = string(str.rbegin(), str.rend());
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
       if(i==0 || j==0) dp[i][j]=0; 
      else if (str[i - 1] == s[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  int left = n - dp[n][n];
  if (left <= k)
    return true; 
  return false;
}
