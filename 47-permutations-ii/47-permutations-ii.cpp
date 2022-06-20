class Solution {
    set<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        vector<vector<int>> vec;
        vec.assign(res.begin(), res.end());
        
        return vec;
    }
    
    void backtrack(vector<int>& nums, int pos) {
        if (pos == nums.size()) {
            vector<int> vec(nums);
            res.insert(vec);
            
            return;
        }
        
        for (int i = pos; i < nums.size(); i++) {
            if (i != pos && nums[i] == nums[i - 1])
                continue;
            
            int temp = nums[pos];
            nums[pos] = nums[i];
            nums[i] = temp;
            
            backtrack(nums, pos + 1);
            
            temp = nums[pos];
            nums[pos] = nums[i];
            nums[i] = temp;
        }
    }
};