class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        //sort(grades.begin(), grades.end());
        int len = grades.size();
        int res = 0;
        int cur = 0;
        for (int i = 1; cur + i <= len; i++) {
            cur += i;
            res++;
        }
        
        return res;
    }
};