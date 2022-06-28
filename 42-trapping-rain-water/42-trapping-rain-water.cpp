class Solution {    // DP. 记事本      O(N)    从 brute force 演化而来
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size <= 2)
            return 0;
        
        vector<int> left_max(size, 0);
        vector<int> right_max(size, 0);
        int cur_left_max = 0;
        int cur_right_max = 0;
        
        for (int i = 1; i < size; i++) {
            left_max[i] = max(cur_left_max, height[i - 1]);
            cur_left_max = max(cur_left_max, left_max[i]);
        }
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(cur_right_max, height[i + 1]);
            cur_right_max = max(cur_right_max, right_max[i]);
        }
        
        int res = 0;
        for (int i = 0; i < size; i++) {
            if (height[i] >= left_max[i] || height[i] >= right_max[i])
                continue;
            else {
                res += min(left_max[i], right_max[i]) - height[i];
                // cout << i << "  " << min(left_max[i], right_max[i]) - height[i] << endl;
            }
        }
        
        return res;
        
    }
};