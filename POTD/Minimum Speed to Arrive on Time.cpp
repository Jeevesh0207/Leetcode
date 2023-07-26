class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        if((double)dist.size()-1>=hour) return -1;
        int L=1;
        int R=(int)10e7;
        while(L<=R){
            int M=(L+R)/2;
            double Total=0;
            for(int i=0;i<n-1;i++){
                Total+=dist[i]/M;
                Total+=(dist[i]%M==0)?0:1;
            }
            Total+=(double)dist[n-1]/M;
            if(Total<=hour) R=M-1;
            else L=M+1;
        }
        return L;
    }
};
