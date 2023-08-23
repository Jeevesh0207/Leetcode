class Solution {
public:
    string reorganizeString(string s) {
        vector<int>arr(26,0);
        for(auto i:s){
            arr[i-'a']++;
        }
        int mx=*max_element(arr.begin(),arr.end());
        int mx_idx=max_element(arr.begin(),arr.end())-arr.begin();
        if(mx>(s.size()+1)/2) return "";
        int idx=0;
        vector<char>a(s.size());
        while(arr[mx_idx]-- > 0){
            a[idx]=char(mx_idx+'a');
            idx+=2;
        }
        for(int i=0;i<arr.size();i++){
            while(arr[i]-- > 0){
                if(idx>=a.size()) idx=1;
                a[idx]=char(i+'a');
                idx+=2;
            }
        }
        string ans="";
        for(auto i:a)ans+=i;
        return ans;
    }
};
