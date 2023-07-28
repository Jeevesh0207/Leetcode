class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>stc;
        for(int i=0;i<n;i++){
            if(stc.empty()) stc.push(s[i]);
            else if(stc.top()=='(' && s[i]==')') stc.pop();
            else if(stc.top()=='{' && s[i]=='}') stc.pop();
            else if(stc.top()=='[' && s[i]==']') stc.pop();
            else stc.push(s[i]);
        }
        return (!stc.size())?true:false;
    }
};
