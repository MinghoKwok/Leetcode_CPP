class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        
        vector<int> index_notOne;
        index_notOne.push_back(-1);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 1) {
                index_notOne.push_back(i);
            }
        }
        index_notOne.push_back(nums.size());
        
        if (index_notOne.size() < k + 2)
            res = index_notOne[index_notOne.size() - 1] - index_notOne[0] - 1;
        else {
            for (int i = 0; i < index_notOne.size(); i++) {
                if (i + k + 1 < index_notOne.size())
                    res = max(res, index_notOne[i + k + 1] - index_notOne[i] - 1);
                else 
                    break;
            }
        }
        
        
        return res;
        
    }
};