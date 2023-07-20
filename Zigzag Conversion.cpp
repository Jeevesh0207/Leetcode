class Solution {
public:
    string convert(string s, int nR) {
       vector<vector<string>>v(nR);
       int c=0,N=-1,P=1,add=0;
       if(nR==1) return s;
       for(int i=0;i<s.size();i++){
           if(c==0){
              add=P;
           }
           string str=string(1,s[i]);
           v[c].push_back(str);
           c+=add;
           if(c==nR){
               add=N;
               c--;
               c+=add;
           }
           
       }
       string ans="";
       for(auto i:v){
         for(auto x:i)ans+=x;
       }
       return ans;
    }
};
