class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int res = 0;
        vector<bool> num_exist(251);
        for (int i = 0; i < nums.size(); i++) {
            num_exist[nums[i]] = true;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (num_exist[nums[i] + diff] && num_exist[nums[i] + diff + diff]) {
                res++;
            }
        }
        
        return res;
    }
};