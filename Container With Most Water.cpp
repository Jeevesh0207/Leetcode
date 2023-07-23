class Solution {
public:
    int maxArea(vector<int>& H) {
       int ans=0,i=0,j=H.size()-1;
       while(i<j){
         int d=min(H[i],H[j]);
         int A=d*(j-i);
         ans=max(ans,A);
         if(H[i]<H[j])i++;
         else j--;
       } 
       return ans;
    }
};
