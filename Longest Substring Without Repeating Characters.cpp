class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int ans=0,L=0,i;
        for(i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()|| mp[s[i]]<L){
                mp[s[i]]=i;
                ans=max(ans,i-L+1);
                
            }
            else {
                L=mp[s[i]]+1;
                mp[s[i]]=i;
            }
        }
        return ans;
    }
};
