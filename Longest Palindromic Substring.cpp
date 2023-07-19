class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int sL=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int L=i,R=i;
            while(L>=0 && R<n && s[L]==s[R]){
                if((R-L+1)>sL){
                    sL=R-L+1;
                    ans=s.substr(L,sL);
                }
                L-=1;
                R+=1;
            }
            L=i,R=i+1;
            while(L>=0 && R<n && s[L]==s[R]){
                if((R-L+1)>sL){
                    sL=R-L+1;
                    ans=s.substr(L,sL);
                }
                L-=1;
                R+=1;
            }
        }
        return ans;
    }
};
