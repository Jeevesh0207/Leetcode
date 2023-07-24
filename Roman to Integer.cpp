class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        unordered_map<char,int>ump;
        ump['I']=1;ump['V']=5;ump['X']=10;ump['L']=50;ump['C']=100;ump['D']=500;ump['M']=1000;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(i==0){
                if(ump[s[0]]<ump[s[1]]){
                ans-=ump[s[0]];
                }
                else ans+=ump[s[0]];
                break;
            }
            if(ump[s[i-1]]<ump[s[i]]){
                ans+=abs(ump[s[i]]-ump[s[i-1]]);
                i--;
            }
            else ans+=ump[s[i]];
        }
        
        return ans;
    }
};
