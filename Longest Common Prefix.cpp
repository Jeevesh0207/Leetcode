class Solution {
public:
    string longestCommonPrefix(vector<string>& a) { 
      vector<int>v;
      string s=a[0];
      for(auto i:s) v.push_back(i-'a');
      int sz=200;
      for(int i=1;i<a.size();i++){
          string str=a[i];
          for(int j=0;j<v.size() && j<str.size();j++){
              if(v[j]!=(str[j]-'a'))
              v[j]=-1;
          }
          sz=min(sz,(int)str.size());
      }
      string ans="";
      for(int i=0;i<v.size() && i<sz;i++){
          if(v[i]!=-1){
              ans+=(s[i]);
          }
          else break;
      }
      return ans;
    }
};
