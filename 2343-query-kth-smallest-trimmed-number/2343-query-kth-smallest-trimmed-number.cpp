class Solution {
    // clarify: trim >= 1;  ki >= 1
    // Time: O(N * M)
private:    
    static int cmp(const pair<string_view, int>& p1, const pair<string_view, int>& p2) {
        if (p1.first == p2.first)
            return p1.second < p2.second;
        
        return p1.first < p2.first;
    }
    
public:
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        
        for (int i = 0; i < queries.size(); i++) {
            int k = queries[i][0];
            int trim = queries[i][1];
            vector<pair<string_view, int>> nums_trim;  // store the trimed nums vector
                                            // pair<val, idx_nums>
            
            // construct nums_trim
            for (int j = 0; j < nums.size(); j++) {
                string_view sv = string_view(nums[j].c_str() + nums[j].size() - trim); // trim
                nums_trim.push_back(pair<string_view, int>(sv, j));
            }
            
            
            sort(nums_trim.begin(), nums_trim.end(), cmp);  // sort trimed strings
            res.push_back(nums_trim[k - 1].second); // k >= 1
        }
        
        
        
        return res;
    }
};