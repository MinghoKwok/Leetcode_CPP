class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        auto it = intervals.begin();
        while (it != intervals.end()) {
            // cout << (*it)[0] << " " << (*it)[1] << endl;
            // cout << newInterval[0] << " " << newInterval[1] << endl << endl;
            if ((*it)[1] >= newInterval[0] && (*it)[0] <= newInterval[1]) {
                
                newInterval[0] = min(newInterval[0], (*it)[0]);
                newInterval[1] = max(newInterval[1], (*it)[1]);
                
            } else {
                res.push_back(*it);
            }
            
            advance(it, 1);
            
        }
        
        //res.push_back(newInterval);
        
        int pos = 0;
        while (pos < res.size() && res[pos][0] < newInterval[0]) {
            pos++;
        }
        res.insert(res.begin() + pos, newInterval);
        
        return res;
    }
};