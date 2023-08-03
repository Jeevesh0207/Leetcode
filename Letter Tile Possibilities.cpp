class Solution {
public:
    set<string>ans;
    unordered_map<int,int>mp;
    string S="";
    void Solve(string s){
      for(int i=0;i<s.size();i++){
        if(!mp[i]){
            S.push_back(s[i]);
            mp[i]=1;
            ans.insert(S);
            Solve(s);
            mp[i]=0;
            S.pop_back();
        }
      }
    }
    int numTilePossibilities(string t) {
        Solve(t);
        return ans.size();
    }
};
