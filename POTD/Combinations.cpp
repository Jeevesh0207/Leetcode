class Solution {
public:
    vector<vector<int>>ans;
    vector<int>T;
    void Solve(int n,int k,int idx){
        if(T.size()==k){
            ans.push_back(T);
            return;
        }
        if(idx>n) return;
        for(int i=idx;i<=n;i++){
                T.push_back(i);
                Solve(n,k,i+1);
                T.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        Solve(n,k,1);
        return ans;
    }
};
