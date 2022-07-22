class Solution {
public:
    int minimumKeypresses(string s) {
        int res = 0;
        
        vector<int> cnt(26, 0);
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
        }
        
        sort(cnt.rbegin(), cnt.rend());
        
        int cnt_1 = 9;
        int cnt_2 = 9;
        
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] == 0)
                break;
            
            if (cnt_1 > 0) {
                res += cnt[i];
                cnt_1--;
            } else if (cnt_2 > 0) {
                res += cnt[i] * 2;
                cnt_2--;
            } else {
                res += cnt[i] * 3;
            }
            
        }
        
        return res;
    }
        
        
};