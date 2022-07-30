class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res = 0;
        sort(boxTypes.rbegin(), boxTypes.rend(), cmp);
        for (int i = 0; i < boxTypes.size(); i++) {
            int cnt = boxTypes[i][0];
            res += min(cnt, truckSize) * boxTypes[i][1];
            truckSize -= cnt;
            if (truckSize <= 0)
                return res;
        }
        
        return res;
    }
    
    
    static int cmp(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
};