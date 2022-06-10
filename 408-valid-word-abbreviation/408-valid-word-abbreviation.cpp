class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        string abbr_word = "";
        int num = 0;
        int w = 0; // index of word
        
        for (int i = 0; i < strlen(abbr.c_str()); i++) {
            if (w == strlen(word.c_str()))
                return false;
            
            if (abbr[i] <= '9' && abbr[i] >= '0') {
                if (num == 0 && abbr[i] == '0')
                    return false;
                
                num = num * 10 + abbr[i] - '0';
                
                if (i == strlen(abbr.c_str()) - 1) {
                    for (int j = 0; j < num; j++) {
                        w++;
                    }
                }
                
                
            } else {
                if (num != 0) {
                    for (int j = 0; j < num; j++) {
                        w++;
                    }
                    num = 0;
                }
                
                if (word[w] != abbr[i])
                    return false;
                w++;
            }
        }
        
        
        if (w != strlen(word.c_str()))
            return false;
        
        
        return true;
        
    }
};