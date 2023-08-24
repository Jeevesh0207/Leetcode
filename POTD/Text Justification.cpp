class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int start = 0, end = words.size() - 1; 
        auto getLine = [&] () -> string {
            vector<string> curr; 
            int character_cnt = 0; 
            for(int i = start; i <= end; i++) {
                if(character_cnt + words[i].size() + curr.size() <= maxWidth) {
                    character_cnt += words[i].size();
                    curr.push_back(words[i]);
                    start++;
                }
                else {
                    break;
                }
            }
            
            string ans = ""; 
            int extraSpaces = maxWidth - character_cnt;
            if(start > end) { 
                for(auto &word : curr) {
                    ans += word;
                    if(extraSpaces) {
                        ans += " ";
                        extraSpaces--;
                    }
                }
                
                while(extraSpaces) {
                    ans += " ";
                    extraSpaces--;
                }
            }
            else {
                int cnt = curr.size() - 1; 
                int spacing = curr.size() - 1 ? extraSpaces / (curr.size() - 1) : 0; 
                int rem = curr.size() - 1 ? extraSpaces % (curr.size() - 1) : 0;
                string empty = spacing ? string(spacing, ' ') : "";
                
                for(auto &word : curr) {
                    ans += word;
                    if(cnt) {
                        ans += empty;
                        cnt--;
                    }
                    
                    if(rem) {
                        ans += ' ';
                        rem--;
                    }
                }
                
                if(curr.size() == 1) {
                    ans += string(extraSpaces, ' ');
                }
            }
            
            return ans;
        };
        
        while(start <= end) { 
            res.push_back(getLine());
        }
        
        return res;
    }
};
