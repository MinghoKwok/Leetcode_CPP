//leetcode.cn/problems/fair-distribution-of-cookies/solution/jian-zhi-hui-su-by-baoya_uncle-7s48/

class Solution {
    int res = INT_MAX;
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> childs(k, 0); // to store each child has how many cookies
        
        backtrack(0, cookies, childs);
        
        return res;
    }
    
    void backtrack(int start, vector<int>& cookies, vector<int>& childs) {
        if (start == cookies.size()) {
            int unfair = childs[0];
            for (int i = 0; i < childs.size(); i++) {
                if (unfair < childs[i])
                    unfair = childs[i];
            }
            
            res = min(res, unfair);
            
            return;
        }
        
        //剪枝
        int zero_cnt = 0;
        for (int i = 0; i < childs.size(); i++) {
            // 剪枝1: 如果当前状态下某位小朋友的饼干数量比当前的答案还多，显然继续回溯下去也无法成为最优答案，直接返回。
            if (childs[i] >= res)
                return;
            
            if (childs[i] == 0)
                zero_cnt++;
        }
        if (zero_cnt > (cookies.size() - start))    // 剪枝2：如果剩余的饼干包不够空手的小朋友分了，直接返回。
            return;
        
        bool track_empty = false;
        for (int i = 0; i < childs.size(); i++) {
            //剪枝3：第一个零食包不管给哪个小朋友，所开启的回溯树都一样，只要给一个小朋友就行了，这样的回溯树一下子就少了很多
            if (childs[i] == 0) {
                if (track_empty)
                    return;
                else 
                    track_empty = true;
            }
            
            childs[i] += cookies[start];
            backtrack(start + 1, cookies, childs);
            childs[i] -= cookies[start];
        }
    }
    
};