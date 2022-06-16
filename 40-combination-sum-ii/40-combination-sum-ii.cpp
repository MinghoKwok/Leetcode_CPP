class Solution {
    set<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> vec_res;
        
        if (accumulate(candidates.begin(), candidates.end(), 0) < target)
            return vec_res;
        
        sort(candidates.rbegin(), candidates.rend());
        vector<int> cur_vec;
        vector<bool> status(candidates.size(), false);  // record if eash element of candidates is used or not, to pruning
        backtrack(candidates, target, 0, cur_vec, status);
        
        
        vec_res.assign(res.begin(), res.end());
        return vec_res;
    }
    
    void backtrack(vector<int>& cand, int target, int index, vector<int>& cur, vector<bool>& status) {
        if (target < 0)
            return;
        
        // int left_sum = 0;
        // for (int i = index; i < cand.size(); i++)
        //     left_sum += cand[i];
        // if (left_sum < target)
        //     return;
        
        if (index == cand.size()) {
            if (target == 0)
                res.insert(cur);
            
            return;
        }
        
        
        cur.push_back(cand[index]);
        if (index != 0 && cand[index] == cand[index - 1] && status[index - 1] == false) {   // pruning
            
        } else {
            status[index] = true;
            backtrack(cand, target - cand[index], index + 1, cur, status);
        }
        
        cur.pop_back();
        status[index] = false;
        backtrack(cand, target, index + 1, cur, status);
    }
    
};