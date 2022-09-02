class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char> s_vec;
        vector<char> t_vec;
        
        s_vec.assign(s.begin(), s.end());
        t_vec.assign(t.begin(), t.end());
        
        sort(s_vec.begin(), s_vec.end());
        sort(t_vec.begin(), t_vec.end());
        
        return s_vec == t_vec;
    }
};