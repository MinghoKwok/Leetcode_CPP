class Solution {
    vector<int> prefixSums;
    
public:
    Solution(vector<int>& w) {
        for (int i = 0; i < w.size(); i++) {
            if (i == 0) {
                prefixSums.push_back(w[i]);
            } else {
                prefixSums.push_back(w[i] + prefixSums.back());
            }
        }
    }
    
    int pickIndex() {
        // generate a random number in the range of [0, 1]
        float randNum = (float) rand() / RAND_MAX;
        float target = randNum * prefixSums.back();
        
        // run a linear search to find the target zone
        for (int i = 0; i < prefixSums.size(); i++) {
            if (target < prefixSums[i])
                return i;
        }
        
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */