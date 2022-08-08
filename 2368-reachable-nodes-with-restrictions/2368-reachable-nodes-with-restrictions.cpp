class Solution {
    unordered_set<int> set_res;
    unordered_set<int> visited;
    vector<vector<int>> vec_edges;
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vec_edges.resize(n);
        
        // construct graph
        for (int i = 0; i < edges.size(); i++) {
            vec_edges[edges[i][0]].push_back(edges[i][1]);
            vec_edges[edges[i][1]].push_back(edges[i][0]);
        }
        
        // Transfer restricted vector to set
        // for (int i = 0; i < restricted.size(); i++) {
        //     set_res.insert(restricted[i]);
        // }
        set_res = unordered_set<int>(restricted.begin(), restricted.end());
        
        // dfs
        dfs(0);
        
        
        
        return visited.size();
    }
    
    void dfs(int num) {
        visited.insert(num);
        for (int i = 0; i < vec_edges[num].size(); i++) {
            int next = vec_edges[num][i];
            if (visited.find(next) == visited.end() && set_res.find(next) == set_res.end()) {
                dfs(next);
            }
        }
    }
};

