class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string res = "";
        
        int i = 0;
        int j = 0;
        while (i < strs[0].size() && j < strs[strs.size() - 1].size()) {
            if (strs[0][i] == strs[strs.size() - 1][j]) {
                res = res + strs[0][i];
                i++;
                j++;
            } else {
                break;
            }
        }
        
        
        return res;
    }
};