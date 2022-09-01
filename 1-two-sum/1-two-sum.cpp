class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;   // num -> indice
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            auto it = mp.find(target - nums[i]);
            if (it != mp.end()) {
                res.push_back(i);
                res.push_back(it->second);
                break;
            }
            
            mp[nums[i]] = i;
        }
        
        
        return res;
    }
};