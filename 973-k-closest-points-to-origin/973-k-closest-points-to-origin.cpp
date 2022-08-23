class Solution {
    // Algorithm: Max Heap/priority_queue
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        
        priority_queue<pair<int, int>> pq; // pair: distance -> index
        
        for (int i = 0; i < points.size(); i++) {
            vector<int> point = points[i];
            int distance = pow(point[0], 2) + pow(point[1], 2);
            pq.push(pair<int, int>(distance, i));
            
            if (pq.size() > k)
                pq.pop();
        }
        
        // for (auto it = pq.begin(); it != pq.end(); it++) {   优先队列不能这么遍历
        //     res.push_back(points[it->second]);
        // }
        
        while (!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return res;
    }
    
    
    
};