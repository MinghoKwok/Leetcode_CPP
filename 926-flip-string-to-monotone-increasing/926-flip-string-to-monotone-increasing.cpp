class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int len = s.size();
        int i = 0;
        int j = len - 1;
        while (i < len && s[i] == '0') {
            i++;
        }
        while (j >= 0 && s[j] == '1') {
            j--;
        }
        if (i > j)
            return 0;
        
        
        int cnt_0 = 0;
        int cnt_1 = 0;
        int pos = i;
        while (pos <= j) {
            if (s[pos] == '0') {
                cnt_0++;
            } else {
                cnt_1++;
            }
            
            pos++;
        }
        
        int res = min(cnt_0, cnt_1);    // 包含全0 和全1 情况
        // 依次设置分界点
        pos = i; // the position that the first '1' occur
        int cur_0 = 0;
        int cur_1 = 0;
        while (pos <= j) {
            // before pos, 1->0
            // since pos, 0->1
            res = min(res, cur_1 + (cnt_0 - cur_0));
            
            if (s[pos] == '0')
                cur_0++;
            else
                cur_1++;
            
            pos++;
        }
        
        
        return res;
    }
};