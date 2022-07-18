class Solution {
private:    
    struct val_index {
        string_view val;
        int index;
    };
    
public:
    static int cmp(const val_index& VI1, const val_index& VI2) {
        if (VI1.val != VI2.val) {
            return VI1.val < VI2.val;
        } else { // ==
            return VI1.index < VI2.index;
        }  
    }
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int len = nums[0].size();
        
        
        // iterate each queries
        for (int i = 0; i < queries.size(); i++) {
            int last = queries[i][1];
            int th = queries[i][0];
            vector<val_index> sort_vec;
            
            for (int j = 0; j < nums.size(); j++) {
                val_index VI;
                VI.index = j;
                VI.val = string_view(nums[j].c_str() + len - last);
                sort_vec.push_back(VI);
            }
            
            sort(sort_vec.begin(), sort_vec.end(), cmp);
            res.push_back(sort_vec[th - 1].index);
        }
        
        return res;
    }
};