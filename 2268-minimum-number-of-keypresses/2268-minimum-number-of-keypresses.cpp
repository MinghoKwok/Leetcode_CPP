class Solution {
public:
    int minimumKeypresses(string s) {
        int res = 0;
        
        map<char, int> cnt; // char in s -> count
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i]]++;
        }
        
        vector<pair<char, int>> vec_cnt;
        for (auto iter = cnt.begin(); iter != cnt.end(); iter++) {
            //cout << iter->first << " " << iter->second << endl;
            vec_cnt.push_back(pair<char, int>(iter->first, iter->second));
        }
        
        sort(vec_cnt.rbegin(), vec_cnt.rend(), cmp);
        int cnt_1 = 9; // press one time
        int cnt_2 = 9;
        
        for (int i = 0; i < vec_cnt.size(); i++) {
            if (cnt_1 > 0) {
                res += vec_cnt[i].second;
                cnt_1--;
            } else if (cnt_2 > 0) {
                res += 2 * vec_cnt[i].second;
                cnt_2--;
            } else {
                res += 3 * vec_cnt[i].second;
            }
        }
        
        return res;
        
    }
    
    int static cmp(const pair<char, int>& p1, const pair<char, int>& p2) {
        return p1.second < p2.second;
    }
};