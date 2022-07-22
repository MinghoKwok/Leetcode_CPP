class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int res = wordsDict.size();
        int pos1 = -1;
        int pos2 = -1;
        
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) {
                pos1 = i;
                if (pos2 != -1) {
                    res = min(res, pos1 - pos2);
                }
            }
            if (wordsDict[i] == word2) {
                pos2 = i;
                if (pos1 != -1) {
                    res = min(res, pos2 - pos1);
                }
            }

        }
        
        
    
        return res;
    }
};