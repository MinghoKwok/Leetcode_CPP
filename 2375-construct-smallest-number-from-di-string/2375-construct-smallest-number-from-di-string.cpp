class Solution {
    // https://leetcode.com/problems/construct-smallest-number-from-di-string/discuss/2422380/JavaC%2B%2BPython-Easy-Reverse
public:
    string smallestNumber(string s) {
        string res, stack;
        for (int i = 0; i <= s.length(); i++) {
            stack.push_back('1' + i);
            if (i == s.length() || s[i] == 'I') {
                while (!stack.empty()) {
                    res.push_back(stack.back());
                    stack.pop_back();
                }
            }
        }
        return res;
    }
};