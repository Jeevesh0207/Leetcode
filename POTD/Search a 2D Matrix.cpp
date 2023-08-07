class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int R=matrix.size();
        int C=matrix[0].size();
        int row=0;
        int col=C-1;
        while(row<R && col>-1){
            int curr=matrix[row][col];
            if(curr==target) return true;
            if(target>curr) row++;
            else col--;
        }
        return false;
    }
};
