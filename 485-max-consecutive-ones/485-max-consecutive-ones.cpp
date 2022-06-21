class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int last = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 1) {
                res = max(res, i - last - 1);
                last = i;
            }
        }
        
        if (res < nums.size() - last)
            res = nums.size() - last - 1;
        
        return res;
    }
};