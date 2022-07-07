class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int alloc = 0;
        int free = 0;
        int res = 0;
        int cur = 0;
        int len = intervals.size();
        
        vector<int> alloc_time;
        vector<int> free_time;
        for (int i = 0; i < len; i++) {
            alloc_time.push_back(intervals[i][0]);
            free_time.push_back(intervals[i][1]);
        }
        
        sort(alloc_time.begin(), alloc_time.end());
        sort(free_time.begin(), free_time.end());
        
        while (alloc < len && free < len) {
            if (alloc_time[alloc] < free_time[free]) {
                cur++;
                res = max(res, cur);
                alloc++;
            } else if (alloc_time[alloc] > free_time[free]) {
                cur--;
                free++;
            } else { // intervals[alloc][0] == intervals[free][1]
                alloc++;
                free++;
            }
        
        }

        
        return res;
    }
};