// Brute Force
class solution{
    public:
    int longestSubsequence(vector<ll>&arr,ll dif){
       ll n=arr.size();
       ll ans=1;
       for(ll i=0;i<n-1;i++){
        ll idx=i,cnt=1;
        for(ll j=i+1;j<n;j++){
            if(arr[j]-arr[i]==dif){
                cnt++;
                i=j;
            }
        }
        ans=max(ans,cnt);
        i=idx;
        
       }
       return ans;
    }
};

// Optimal Approach
class solution{
    public:
    int longestSubsequence(vector<ll>&arr,ll dif){
        ll n=arr.size();
        unordered_map<ll,ll>mp;
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(mp.find(arr[i]-dif)!=mp.end()){
                mp[arr[i]]=mp[arr[i]-dif]+1;
            }
            else mp[arr[i]]=1;
            ans=max(ans,mp[arr[i]]);
        }
        return ans;
    }
};
