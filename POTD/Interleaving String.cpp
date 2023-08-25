class Solution {
      bool help(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<int>>& dp) {

        if (i == s1.size() && j == s2.size() && k == s3.size()) { //base case 
            return true;   
        }
        
        if (dp[i][j] != -1) {  //check is dp array
            return dp[i][j];
        }
        
        bool result = false;   //first false check s1 ,s2 element not present then return false as always
        if (i < s1.size() && s1[i] == s3[k]) { 
            result = help(s1, s2, s3, i + 1, j, k + 1, dp);//check s1 and s3 
        }
        if (result==false && j < s2.size() && s2[j] == s3[k]) {

            result = help(s1, s2, s3, i, j + 1, k + 1, dp); //check s2 and s3
        }
        dp[i][j] = result;
        return result;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int k = s3.size();

        if (m + n != k) {
            return false;   // when size of s3 is larger
        }
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return help(s1, s2, s3, 0, 0, 0, dp);
    }
};
