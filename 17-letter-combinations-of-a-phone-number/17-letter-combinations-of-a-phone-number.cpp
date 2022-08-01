class Solution {
    vector<string> res;
    map<char, string> mp;
    string dgts;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return res;
        
        dgts = digits;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        backtrack(0, "");
        
        return res;
    }
    
    
    void backtrack(int index, string cur) {
        if (index == dgts.size()) {
            res.push_back(cur);
            return;
        }
        
        char c = dgts[index];
        for (int i = 0; i < mp[c].size(); i++) {
            backtrack(index + 1, cur + mp[c][i]);
        }
        
    }
    
    
};