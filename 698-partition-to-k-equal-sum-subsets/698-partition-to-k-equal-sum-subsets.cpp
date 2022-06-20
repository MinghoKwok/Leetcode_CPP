class Solution {
    int ave;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;
        ave = sum / k;
        
        sort(nums.rbegin(), nums.rend());
        vector<int> subs(k, 0);
        
        return backtrack(0, nums, subs);
    }
    
    bool backtrack(int pos, vector<int>& nums, vector<int>& subs) {
        if (pos == nums.size()) {
            bool res = true;
            for (int i = 0; i < subs.size(); i++) {
                if (subs[i] != ave)
                    res = false;
            }
            
            return res;
        }
        
        
        for (int i = 0; i < subs.size(); i++) {
            if (i != 0 && subs[i] == subs[i - 1])
                continue;
            
            subs[i] += nums[pos];
            if (subs[i] <= ave)
                if (backtrack(pos + 1, nums, subs))
                    return true;
            subs[i] -= nums[pos];
        }
        
        return false;
    }
};