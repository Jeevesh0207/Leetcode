//https://www.codingninjas.com/studio/problems/palindromic-substrings_630404

int palindromicSubstrings(string I)
{
    int n=I.size();
    int ans=0;
    for(int i=0;i<n;i++){
        int L=i;
        int R=i;
        while(L>=0 && R<n){
            if(I[L]==I[R]){
                ans++;
                L--;
                R++;
            }
            else break;
        }
        L=i;
        R=i+1;
        while(L>=0 && R<n){
            if(I[L]==I[R]){
                ans++;
                L--;
                R++;
            }
            else break;
        }

    }
    return ans;
}
