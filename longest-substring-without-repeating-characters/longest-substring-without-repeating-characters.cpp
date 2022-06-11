class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        string str = "";
        int pos = 0;
        
        while (pos < s.size()) {
            if (str.find(s[pos]) != str.npos) {
                while (str.find(s[pos]) != str.npos) {
                    str.erase(0, 1);
                }
            }
            str += s[pos];
            
            if (str.size() > res)
                res = str.size();
            
            pos++;
        }
        
        return res;
    }
};