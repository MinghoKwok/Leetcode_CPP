class Solution {
    // https://leetcode.cn/problems/sliding-window-maximum/solution/shuang-xiang-dui-lie-jie-jue-hua-dong-chuang-kou-2/
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> buffer; // from large to small, record index of num, the first num is the max one
        int l = 0, r = 0;
        
        // construct buffer
        while (r < k) {
            while (!buffer.empty() && nums[buffer.back()] < nums[r]) {
                buffer.pop_back();
            }
            
            // make sure nums[r] <= nums[buffer.back()]
            buffer.push_back(r);
            
            r++;
        }
        
        // r == k, slide the window
        res.push_back(nums[buffer.front()]);
        l++;
        while (r <= nums.size() - 1) {
            // clear the index in front left num
            while (!buffer.empty() && buffer.front() < l) {
                buffer.pop_front();
            }
            // push the nums[r]
            while (!buffer.empty() && nums[buffer.back()] < nums[r]) {
                buffer.pop_back();
            }
            buffer.push_back(r);
            
            // add to result
            res.push_back(nums[buffer.front()]);
            
            l++;r++;
        }
        
        return res;
        
    }
};