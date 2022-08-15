class Solution {
    // We could have used 2 sets to keep a record of rows/columns which need to be set to zero. But for an O(1) space solution, you can use one of the rows and and one of the columns to keep track of this information.
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 1 && n == 1)
            return;
        
        // matrix[0][j] to record the num of each row
        // matrix[i][0] to record the num of each column
        
        // Record if row_0 and col_0 have 0
        bool row_0 = false;
        bool col_0 = false;
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0)
                row_0 = true;
        }
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0)
                col_0 = true;
        }
        
        // Record other rows and cols
        // Rows
        for (int i = 1; i < m; i++) {
            //matrix[i][0] = 1;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    break;
                }
            }
        }
        // Cols
        for (int j = 1; j < n; j++) {
            //matrix[0][j] = 1;
            for (int i = 0; i < m; i++) {
                // if (i == 0 && j == 3)
                //     cout << matrix[i][j];
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    break;
                }
            }
        }
        
        
        // Set zero
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
            }
        }
        
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++)
                    matrix[i][j] = 0;
            }
        }
        
        if (row_0) {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
        
        if (col_0) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
        
    }
};