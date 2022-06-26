class Solution {
    unordered_set<int> visited;
    vector<int> cnt_graph; // Count how many nodes in each graph
    vector<vector<int>> graphs;
public:
    void dfs(int node, int& graph) {
        graph++;
        visited.insert(node);
        for (int i = 0; i < graphs[node].size(); i++) {
            if (visited.find(graphs[node][i]) == visited.end()) {
                dfs(graphs[node][i], graph);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        graphs.resize(n);
        
        // construct the graph
        for (int i = 0; i < edges.size(); i++) {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            graphs[node1].push_back(node2);
            graphs[node2].push_back(node1);
        }
        
        long long res = 0;
        int visit = 0;
        for (int i = 0; i < n; i++) {
            if (visited.find(i) == visited.end()) {
                int graph = 0;
                dfs(i, graph);
                cnt_graph.push_back(graph);
                
                res += (long long)visit * (long long)graph;
                visit += graph;
            }
        }
        
        
        // for (int i = 0; i < cnt_graph.size() - 1; i++) {
        //     for (int j = i + 1; j < cnt_graph.size(); j++) {
        //         res += (long long)cnt_graph[i] * (long long)cnt_graph[j];
        //     }
        // }
        
        return res;
    }
};