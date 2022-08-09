class Solution {
    // Clarification: Is [1,2] and [2,3] overlap?
    // start and end > 0?
    // Greedy: sort by end, choose the most left end every time
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int cnt_erase = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int last_right = intervals[0][0];
        
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] >= last_right) {
                last_right = intervals[i][1];
            } else {
                cnt_erase++;
            }
        }
        
        return cnt_erase;
    }
    
    static int cmp(const vector<int>& vec1, const vector<int>& vec2) {
        if (vec1[1] == vec2[1]) {
            return vec1[0] < vec2[0];
        } else {
            return vec1[1] < vec2[1];
        }
    }
};