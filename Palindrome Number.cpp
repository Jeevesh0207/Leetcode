class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        string str=string(s.rbegin(),s.rend());
        return s==str;
    }
};
