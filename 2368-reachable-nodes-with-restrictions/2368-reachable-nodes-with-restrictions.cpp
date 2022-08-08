class Solution {
    //unordered_set<int> set_res;
    vector<bool> visited;
    vector<vector<int>> vec_edges;
    int cnt = 0;
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vec_edges.resize(n);
        visited.resize(n);
        
        // construct graph
        for (int i = 0; i < edges.size(); i++) {
            vec_edges[edges[i][0]].push_back(edges[i][1]);
            vec_edges[edges[i][1]].push_back(edges[i][0]);
        }
        
        // Transfer restricted vector to set
        for (int i = 0; i < restricted.size(); i++) {
            visited[restricted[i]] = true;  // 直接加入 visited 即可，后面可以少一个判断
        }
        //set_res = unordered_set<int>(restricted.begin(), restricted.end());
        
        // dfs
        dfs(0);
        
        
        
        return cnt;
    }
    
    void dfs(int num) {
        visited[num] = true;
        cnt++;
        for (int i = 0; i < vec_edges[num].size(); i++) {
            int next = vec_edges[num][i];
            if (!visited[next]) {
                dfs(next);
            }
        }
    }
};

