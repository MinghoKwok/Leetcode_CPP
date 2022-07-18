class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        //sort(numsDivide.begin(), numsDivide.end());
        
        int gcd_res = numsDivide[0];
        for (int i = 0; i < numsDivide.size() - 1; i++) {
            gcd_res = gcd(gcd_res, numsDivide[i + 1]);
        }
        
        cout << gcd_res << endl;
        
        int res = 0;
        while (res < nums.size()) {
            if (gcd_res % nums[res] == 0) {
                break;
            } else {
                res++;
            }
        }
        
        if (res == nums.size())
            res = -1;
        
        return res;
    }
};