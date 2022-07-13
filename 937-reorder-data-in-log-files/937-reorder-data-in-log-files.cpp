class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        std::stable_sort(logs.begin(), logs.end(), [](auto& s1, auto& s2) {
            int pos1 = s1.find_first_of(' ');
            int pos2 = s2.find_first_of(' ');
            if (isdigit(s1[pos1 + 1]) && isdigit(s2[pos2 + 1])) {
                return false;
            } else if (!isdigit(s1[pos1 + 1]) && !isdigit(s2[pos2 + 1])) {
                string_view sv1(s1.c_str() + pos1);
                string_view sv2(s2.c_str() + pos2);
                if (sv1 == sv2) {
                    string_view sv01(s1.c_str(), pos1);
                    string_view sv02(s2.c_str(), pos2);
                    return sv01 < sv02;
                }
                
                return sv1 < sv2;
            } else if (isdigit(s1[pos1 + 1]) && !isdigit(s2[pos2 + 1])) {
                return false;
            } else if (!isdigit(s1[pos1 + 1]) && isdigit(s2[pos2 + 1])) {
                return true;
            } 
            
            return false;
        });
        
        return logs;
    }

        
};