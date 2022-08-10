class Solution {
    // clarify: distance of diagonal
    
    
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX - 1));
        
        
        // LeftTop to RightBottom
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0)
                    dis[i][j] = 0;
                else {
                    if (i > 0)
                        dis[i][j] = min(dis[i][j], dis[i - 1][j] + 1);
                    if (j > 0)
                        dis[i][j] = min(dis[i][j], dis[i][j - 1] + 1);
                }
            }
        }
        
        
        
        // RightBottom to LeftTop
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i < m - 1)
                    dis[i][j] = min(dis[i][j], dis[i + 1][j] + 1);
                if (j < n - 1)
                    dis[i][j] = min(dis[i][j], dis[i][j + 1] + 1);
            }
        }
        
        
        
        
        return dis;
    }
    
};