class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        
        backtrack(nums, cur, nums.size());
        
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int>& cur, int size) {
        if (size == 0) {
            res.push_back(cur);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            cur.push_back(val);
            nums.erase(nums.begin() + i);
            backtrack(nums, cur, size - 1);
            cur.pop_back();
            nums.insert(nums.begin() + i, val);
        }
    }
};