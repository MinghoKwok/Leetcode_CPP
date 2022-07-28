class Solution {
    // https://leetcode.cn/problems/append-k-integers-with-minimal-sum/solution/zhe-ti-bi-sai-de-shi-hou-zhen-shi-zhe-mo-bor8/
public:
    long long minimalKSum(vector<int>& nums, int k) {
        // 排序为了去重 也方面k后移
        sort(nums.begin(), nums.end());
        int n = unique(nums.begin(), nums.end()) - nums.begin(); // 所谓的去重只是把多余的数移到了最后面并没有删除
        long long d = 0;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] <= k)
            {
                d += nums[i];
                ++k;
            }
        }
        return (1LL + k) * k / 2 - d;
    }
};


