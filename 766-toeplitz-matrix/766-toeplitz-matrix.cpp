class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int x = 0, y = 0;
        
        while (x < m) {
            int i = x, j = y;
            int num = matrix[i][j];
            while (i < m && j < n) {
                if (matrix[i][j] != num)
                    return false;
                
                i++;
                j++;
            }
            
            x++;
        }
        
        
        x = 0, y = 0;
        
        while (y < n) {
            int i = x, j = y;
            int num = matrix[i][j];
            while (i < m && j < n) {
                if (matrix[i][j] != num)
                    return false;
                
                i++;
                j++;
            }
            
            y++;
        }
        
        return true;
        
    }
};