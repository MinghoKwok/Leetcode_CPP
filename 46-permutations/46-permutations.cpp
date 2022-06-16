class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur(nums.size(), 11);
        
        backtrack(nums, cur, nums.size());
        
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int>& cur, int size) {
        if (size == 0) {
            res.push_back(cur);
            return;
        }
        
        int val = nums[nums.size() - size];
        for (int i = 0; i < cur.size(); i++) {
            if (cur[i] == 11) {
                cur[i] = val;
                backtrack(nums, cur, size - 1);
                cur[i] = 11;
            }
        }
    }
};