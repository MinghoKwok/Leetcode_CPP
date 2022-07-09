class Solution {
    // https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/solution/by-autistic-k-pgm1/
    // O(N)
public:
    int uniqueLetterString(string s) {
        int res = 0;
        int len = s.size();
        vector<vector<int>> c_i(26, vector<int>(1, -1));
        int dp[len]; // count of unique char of substring include last cha
        dp[0] = 1;
        res = dp[0];
        c_i[s[0] - 'A'].push_back(0);
        
        for (int i = 1; i < len; i++) {
            int index = s[i] - 'A';
            int last1 = c_i[index][c_i[index].size() - 1];
            if (last1 == -1) { // not exist
                dp[i] = dp[i - 1] + i + 1;
            } else {
                int last2 = c_i[index][c_i[index].size() - 2];
                if (last2 == -1) { // only once
                    dp[i] = dp[i - 1] - (last1 + 1) + (i - last1 - 1) + 1;
                } else {
                    dp[i] = dp[i - 1] + i + 1 - 2 * (last1 - last2) - (last2 + 1);
                }
                
            }
            
            
            
            c_i[index].push_back(i);
            
            res += dp[i];
        }
        
        return res;
    }
    
};