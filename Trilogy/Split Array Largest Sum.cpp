//https://www.codingninjas.com/studio/problems/split-the-given-array-into-k-sub-arrays_1215015?leftPanelTab=0

int isTrue(vector<int>&arr,int M){
	int sum=0;
	int count=1;
	for(int i=0;i<arr.size();i++){
		if(sum+arr[i]>M){
			sum=arr[i];
			count++;
		}
		else{
			sum+=arr[i];
		}
	}
	return count;
}

int splitArray(vector<int> &arr, int k) {
	int Low=0;
	int High=0;
	for(auto i:arr){
		Low=max(Low,i);
		High+=i;
	}
	int ans=Low;
	while(Low<=High){
       int M=(Low+High)/2;
	   int Sub_Count=isTrue(arr,M);
	   if(Sub_Count>k){
		   Low=M+1;
	   }
	   else{
		   ans=M;
		   High=M-1;
	   }
	}
	return ans;
}
