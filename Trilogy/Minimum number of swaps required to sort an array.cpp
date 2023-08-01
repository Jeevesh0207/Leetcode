//https://www.codingninjas.com/studio/problems/minimum-number-of-swaps-required-to-sort-an-array_973251?leftPanelTab=1

#include<bits/stdc++.h>
int minSwaps(vector<int> &arr)
{
	long n=arr.size();
	vector<pair<long,long>>v(n);
	for(int i=0;i<n;i++) v[i]={arr[i],i};
	sort(v.begin(),v.end());
	long ans=0;
	long i=0;
	for(long i=0;i<n;i++){
       if(v[i].second!=i){
		   ans++;
		   swap(v[i],v[v[i].second]);
		   i--;
		}
	}
	return ans;
}
