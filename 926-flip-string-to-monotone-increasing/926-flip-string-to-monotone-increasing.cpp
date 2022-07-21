class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int N = s.size();
        vector<int> P(N + 1, 0); // record the cnt of '1'
        for (int i = 0; i < N; i++) {
            P[i + 1] = P[i] + (s[i] - '0');
        }
        
        int res = N;
        for (int i = 0; i <= N; i++) {
            res = min(res, P[i] + N - i - (P[N] - P[i]));
        }
        
        return res;
    }
};