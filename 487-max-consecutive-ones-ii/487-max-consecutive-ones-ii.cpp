#include<algorithm>

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int last1 = -1;
        int last2 = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 1) {
                res = max(res, i - last1 - 1);
                last1 = last2;
                last2 = i;
            }
        }
        
        res = max(res, (int)(nums.size() - last1 - 1));
        
        return res;
    }
};