//!---------- Brute Force ----------//
class solution{
    public:
    vector<ll> twoSum(vector<ll>&arr,ll T){
       ll a=0,b=0; 
       ll n=arr.size();
       for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            if(arr[i]+arr[j]==T) return {i,j};
        }
       }
       return {a,b};
    }
};

//!---------- Optimal Approach ----------//

class solution{
    public:
    vector<ll> twoSum(vector<ll>&arr,ll T){
       ll n=arr.size();
       unordered_map<ll,ll>mp1,mp2;
       for(ll i=0;i<n;i++){
        if(mp2.find(T-arr[i])!=mp2.end()){
            return {mp1[T-arr[i]],i};
        }
        else{
            mp1[arr[i]]=i;
            mp2[arr[i]]++;
        }
       }
       return {0,0};
    }
};

//!---------- Optimal Approach ----------//

class solution{
    public:
    vector<ll> twoSum(vector<ll>&arr,ll T){
       vector<ll>V=arr; 
       ll n=arr.size(); 
       sort(arr.begin(),arr.end());
       ll L=0,R=arr.size()-1;
       while(L<R){
         if(arr[L]+arr[R]==T){
            break;
         }
         else if(arr[L]+arr[R]>T){
            R--;
         }
         else L++;
       }
       for(ll i=0;i<n;i++){
        if(arr[L]==V[i]){
            L=i;
            break;
        }
       }
       for(ll i=0;i<n;i++){
        if(arr[R]==V[i] && i!=L){
            R=i;
            break;
        }
       }
       return {L,R};
    }
};
