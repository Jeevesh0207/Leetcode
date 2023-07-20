class Solution {
public:
    
    vector<int> asteroidCollision(vector<int>& A) {
        stack<int>s;
        int n=A.size();
        for(int i=0;i<n;i++){
           while(!s.empty() && A[i]<0 && s.top()>0){
               int dif=A[i]+s.top();
               if(dif<0) s.pop();
               else if(dif>0) A[i]=0;
               else{
                   A[i]=0;
                   s.pop();
               }
           }
           if(A[i]) s.push(A[i]);
        }
        A.clear();
        while(!s.empty()){
            A.push_back(s.top());
            s.pop();
        }
        for(int i=0;i<A.size()/2;i++){
            swap(A[i],A[A.size()-i-1]);
        }
        return A;
    }
};
