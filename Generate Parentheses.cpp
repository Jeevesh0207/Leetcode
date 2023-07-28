class Solution {
public:
    vector<string>ans;
    
    void Solve(int n,int L,int R,string s){
        cout<<s<<endl;
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(L!=n)
        Solve(n,L+1,R,s+"(");
        if(L>R)
        Solve(n,L,R+1,s+")");
    }
    vector<string> generateParenthesis(int n) {
        Solve(n,0,0,"");
        return ans;
    }
};
