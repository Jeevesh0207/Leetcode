/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*>Solve(int i,int n){
        vector<TreeNode*>v;
        if(i>n){
            v.push_back(NULL);
            return v;
        }
        if(i==n){
            v.push_back(new TreeNode(i));
            return v;
        }
        for(int j=i;j<=n;j++){
            auto left=Solve(i,j-1);
            auto right=Solve(j+1,n);
            for(auto L:left){
                for(auto R:right){
                    TreeNode* root=new TreeNode(j);
                    root->left=L;
                    root->right=R;
                    v.push_back(root);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
       return Solve(1,n);
    }
};
