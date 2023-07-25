class Solution {
public:
    vector<string>ans;
    unordered_map<int,string>mp;
    void Solve(string s,int n,int idx,string str){
        if(str.size()==n){
           ans.push_back(str);
           return;
        }
        string S=mp[s[idx]-'0'];
        for(int i=0;i<S.size();i++){
          Solve(s,n,idx+1,str+S[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        mp[2]="abc";mp[3]="def";mp[4]="ghi";mp[5]="jkl";mp[6]="mno";mp[7]="pqrs";mp[8]="tuv";mp[9]="wxyz";
        int n=digits.size();
        if(digits=="") return ans;
        Solve(digits,n,0,"");
        return ans;
    }
};
