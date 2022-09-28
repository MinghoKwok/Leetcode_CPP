class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        
        int res = 0;
        int l = 0, r = 0;
        map<char, int> mp; // char -> cnt
        mp[s[r]]++;
        
        while (r <= s.size() - 1) {
            res = max(res, r - l + 1);
            //cout << res << endl;
            
            r++;
            
            if (r <= s.size() - 1 && mp[s[r]] > 0) {
                while (s[l] != s[r]) {
                    mp[s[l]]--;
                    l++;
                }
                
                // s[l] == s[r]
                l++;
            } else {
                mp[s[r]]++;
            }
            
            
        }
        
        
        return res;
    }
};