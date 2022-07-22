class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> pos1;
        vector<int> pos2;
        
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1)
                pos1.push_back(i);
            if (wordsDict[i] == word2)
                pos2.push_back(i);
        }
        
        int res = wordsDict.size();
        int i = 0;
        int j = 0;
        while (i < pos1.size() && j < pos2.size()) {
            if (pos1[i] < pos2[j]) {
                res = min(res, pos2[j] - pos1[i]);
                i++;
            } else {
                res = min(res, pos1[i] - pos2[j]);
                j++;
            }
        }
        
    
        return res;
    }
};