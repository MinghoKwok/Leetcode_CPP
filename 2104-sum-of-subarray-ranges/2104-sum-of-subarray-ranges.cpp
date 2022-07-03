class Solution {
    long long res = 0;
public:
    long long subArrayRanges(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return 0;
        
        long long res = 0;
        
        vector<vector<int>> max_vec(len);
        vector<vector<int>> min_vec(len);
        
        for (int i = 0; i < len; i++) {
            vector<int> max_v(len);
            max_vec[i] = max_v;
            vector<int> min_v(len);
            min_vec[i] = min_v;
        }
        
        // initial
        for (int i = 0; i < len; i++) {
            max_vec[i][i] = nums[i];
            min_vec[i][i] = nums[i];
        }
        
        for (int step = 1; step < len; step++) {
            for (int start = 0; start + step < len; start++) {
                max_vec[start][start + step] = max(max_vec[start][start + step - 1], nums[start + step]);
                //cout << "max: " << max_vec[start][start + step] << endl;
                min_vec[start][start + step] = min(min_vec[start][start + step - 1], nums[start + step]);
                //cout << "min: " << min_vec[start][start + step] << endl;
                long long dif = (long long)max_vec[start][start + step] - (long long)min_vec[start][start + step];
                //cout << "dif: " << dif << endl;
                res += dif;
            }
        }
        
       
        return res;
        
    }
    
    
};