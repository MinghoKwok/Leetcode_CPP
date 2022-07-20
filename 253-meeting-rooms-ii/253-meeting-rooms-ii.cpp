class Solution {
/*  1. Clarification
    1) length of intervals array; range of intervals.length and start/end
    2) intervals[i][1] > intervals[i][0]?
    3) if meetA start at time1, meetB end at time1, then in time1, do these two rooms only need one room?
    
    2. Example
    1) [[0,1], [3,4]]
    2) [[0,3], [2,4]]
    
    3. Solution
    1) algo
    cur_room
    two arrays -> start time    cur_room++
               -> end time      cur_room--
    
    2） input/output
        input:  vector<vector<int>>&
        output: int
    3) corner case
    4)  Time complexity  O(nlogn)
        Space complexity O(N)
    
    
*/
    
    
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int res = 0;
        int cur_room = 0;
        vector<int> starts;
        vector<int> ends;
        for (int i = 0; i < intervals.size(); i++) {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int i = 0; // starts
        int j = 0; // ends
        
        while (i < starts.size() && j < ends.size()) {
            if (starts[i] == ends[j]) {
                i++;
                j++;
            } else if (starts[i] < ends[j]) {
                cur_room++;
                res = max(res, cur_room);
                i++;
            } else {
                cur_room--;
                j++;
            }
        }
        
         
        return res;
    }
};