class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (char c : s) {
            if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
                str += c;
            }
            
            if (c >= 'A' && c <= 'Z') {
                str += (char)('a' + c - 'A'); 
            }
        }
        
        if (str.size() <= 1)
            return true;
        
        int l = 0;
        int r = str.size() - 1;
        while (r > l) {
            if (str[l] != str[r])
                return false;
            else {
                l++;
                r--;
            }
        }
        
        return true;
    }
    
};