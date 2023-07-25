class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int L=0,R=n-1;
        int ans=0;
        while(L<R){
            int M=(L+R)/2;
            if(arr[M-1]<arr[M] && arr[M]>arr[M+1]){
                ans=M;
                return M;
            }
            else if(arr[M]<arr[M+1]){
                L=M;
            }
            else{
                R=M;
            }
        }
        return ans;
    }
};
