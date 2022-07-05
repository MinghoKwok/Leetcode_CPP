class Solution {
    // https://leetcode.cn/problems/number-of-people-aware-of-a-secret/solution/by-endlesscheng-2x0z/
    // Fib
    const int MOD = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int sum[n + 1]; // sum = f1 + f2 + ... + fn.   f means how many new persons know the secret in ith days
        sum[0] = 0;
        sum[1] = 1;
        
        // construct sum        n >= 2
        for (int i = 2; i <= n; i++) {
            int f = sum[max(i - delay, 0)] - sum[max(i - forget, 0)];    // how many new persons know the secret in ith days
            sum[i] = (sum[i - 1] + (f % MOD)) % MOD;
        }
        
        return ((sum[n] - sum[max(n - forget, 0)]) % MOD + MOD) % MOD;
    }
};