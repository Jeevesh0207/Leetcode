class Solution {
public:
    int n;
    vector<vector<int>>T;
    int solve(vector<vector<int>>& events,int idx,int k){
        if(idx>=n || k==0) return 0;
        if(T[idx][k]!=-1) return T[idx][k];
        int start=events[idx][0];
        int end=events[idx][1];
        int value=events[idx][2];
        //Skip
        int Skip=solve(events,idx+1,k);
        //Take
        vector<int>v={end,INT_MAX,INT_MAX};
        int j=upper_bound(events.begin()+idx+1,events.end(),v)-events.begin(); 
        int Take=value+solve(events,j,k-1);
        return T[idx][k]= max(Skip,Take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        n=events.size();
        sort(begin(events),end(events));
        T.resize(n+1,vector<int>(k+1,-1));
        return solve(events,0,k);
    }
};
