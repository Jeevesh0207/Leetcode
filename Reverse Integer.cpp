class Solution {
public:
    long long reverse(long long x) {
      bool neg=false;
      if(x<0){
        neg=true;
        x*=-1;
      }
      string s=to_string(x);
      s=string(s.rbegin(),s.rend());
      long long n=0;
      for(long long i=0;i<s.size();i++){
          n=n*10+(s[i]-'0');
      }
      (neg)?n*=-1:neg*=1;
      if(n<INT_MIN || n>INT_MAX) return 0;
      return n;  
    }
};
