class WordDistance {
private:
    unordered_map<string, vector<int>> mp; // word->indexs
    int len;
public:
    WordDistance(vector<string>& wordsDict) {
        len = wordsDict.size();
        for (int i = 0; i < wordsDict.size(); i++) {
            mp[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int i = 0;
        int j = 0;
        int res = len;
        
        while (i < mp[word1].size() && j < mp[word2].size()) {
            int pos1 = mp[word1][i];
            int pos2 = mp[word2][j];
            if (pos1 < pos2) {
                res = min(res, pos2 - pos1);
                i++;
            } else {
                res = min(res, pos1 - pos2);
                j++;
            }
        }
        
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */