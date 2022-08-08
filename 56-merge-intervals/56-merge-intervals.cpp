class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        vector<int> cur(2);
        cur = intervals[0];
        
        int pos = 1;
        while (pos < intervals.size()) {
            if (intervals[pos][0] > cur[1]) { // no overlap
                res.push_back(cur);
                cur = intervals[pos];
            } else {
                cur[0] = min(cur[0], intervals[pos][0]);
                cur[1] = max(cur[1], intervals[pos][1]);
            }
            
            pos++;
        }
        res.push_back(cur);
        
        
        return res;
    }
};