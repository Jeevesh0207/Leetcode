class Solution {
public:
    bool isGood(vector<int>& B, ll M , ll N){
        ll Total=0;
        FOR(i,0,B.size()){
            if(B[i]<M) Total+=B[i];
            else Total+=M;
        }
        return (Total)>=N*M;
    }
    long long maxRunTime(int N, vector<int>& B) {
        ll L=0;
        ll R=0;
        FORA(i,B) R+=i;
        ll ans=0;
        while(L<=R){
            ll M=(L+R)/2;
            if(isGood(B,M,N)){
                ans=M;
                L=M+1;
            }
            else R=M-1;
        }
        return ans;
    }
};
