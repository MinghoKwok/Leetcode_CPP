class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        vector<string> rows(numRows, "");
        int row = 0;
        bool down = true;
        
        for (int i = 0; i < s.size(); i++) {
            rows[row] += s[i];
            if (down) {
                 
                if (row == numRows - 1) {
                    down = false;   // set up
                    row--;
                } else {
                    row++;
                }
            } else {    // up
                if (row == 0) {
                    down = true;
                    row++;
                } else {
                    row--;
                }
            }
        }
        
        string res = "";
        for (int i = 0; i < rows.size(); i++) {
            res += rows[i];
        }
        
        return res;
    }
};