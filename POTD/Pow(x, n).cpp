class Solution {
public:
    double myPow(double x, long long n) {
        long double res=1;
        bool check=false; 
        if(n<0) {
            check=true;
            n*=-1;
        }
        if(n>0)
        while(n>0){
            if(n%2) res*=x;
            x*=x;
            n/=2;
        }
        if(check) return (double)1/res;
        return res;
    }
};
