class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        vector<string> res;
        unordered_map<string, map<int, string>> mp; // username -> (time -> website)
        unordered_map<string, int> cnt; // pattern -> count
        
        for (int i = 0; i < username.size(); i++) {
            mp[username[i]][timestamp[i]] = website[i];
        }
        
        for (auto it_mp = mp.begin(); it_mp != mp.end(); it_mp++) {
            set<string> cur_user; // what patterns this user has
            for (auto it1 = it_mp->second.begin(); it1 != it_mp->second.end(); it1++) {
                for (auto it2 = next(it1); it2 != it_mp->second.end(); it2++) {
                    for (auto it3 = next(it2); it3 != it_mp->second.end(); it3++) {
                        string str = it1->second + '$' + it2->second + '@' + it3->second;
                        cur_user.insert(str);
                    }
                }
            }
            
            for (auto str : cur_user) {
                cnt[str]++;
            }
        }
        
        
        // find largest value and corresponding res_str
        string res_str;
        int max_cnt = -1;
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            if (max_cnt < it->second) {
                max_cnt = it->second;
                res_str = it->first;
            } else if (max_cnt == it->second) {
                if (res_str > it->first)
                    res_str = it->first;
            } else {
                continue;
            }
        }
        // decode the res_str
        int pos1 = res_str.find('$');
        int pos2 = res_str.find('@');
        res.push_back(res_str.substr(0, pos1));
        res.push_back(res_str.substr(pos1 + 1, pos2 - pos1 - 1));
        res.push_back(res_str.substr(pos2 + 1));
        
        
        return res;
    }
    
    
};