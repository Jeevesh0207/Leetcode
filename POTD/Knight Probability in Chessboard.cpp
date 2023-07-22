class Solution {
public:
    int arr[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    double dp[101][101][101]={0};
    double knightProbability(int n, int k, int row, int col) {
        if(isValid(row,col,n)==false) return 0;
        if(k==0) return 1;
        if(dp[row][col][k]!=0) return dp[row][col][k];
        double prob=0;
        for(int i=0;i<8;i++){
            prob+=knightProbability(n,k-1,row+arr[i][0],col+arr[i][1])/8.0;
        }
        dp[row][col][k]+=prob;
        return prob;
    }
    bool isValid(int row,int col,int n){
        if(row<0 || row>=n || col<0 || col>=n) return false;
        else return true;
    }
};
