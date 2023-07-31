//https://www.codingninjas.com/studio/problems/stocks-are-profitable_893405

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &p){
    int n=p.size();
    int ans=0;
    int min_p=INT_MAX;
    for(int i=1;i<n;i++){
        if(p[i-1]<p[i]){
            min_p=min(min_p,p[i-1]);
            ans=max(ans,p[i]-min_p);
        }
    }
    return ans;
}
