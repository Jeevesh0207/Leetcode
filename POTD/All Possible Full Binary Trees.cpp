class Solution {
public:
    vector<vector<TreeNode*>>dp;
    vector<TreeNode*>FindAll(int n){
        if(n==0) return {};
        if(n==1) return {new TreeNode(0)};
        if(dp[n].size()) return dp[n];
        vector<TreeNode*>ans;
        for(int i=0;i<n;i++){
           int R=n-i-1; 
           vector<TreeNode*> Left=FindAll(i);
           vector<TreeNode*> Right=FindAll(R);
           for(TreeNode *j: Left){
               for(TreeNode *k: Right){
                   TreeNode* root = new TreeNode(0);
                   root->left=j;
                   root->right=k;
                   ans.push_back(root);
               }
           }
        }
        dp[n]=ans;
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        dp.resize(n+1);
        return FindAll(n);
    }
};
