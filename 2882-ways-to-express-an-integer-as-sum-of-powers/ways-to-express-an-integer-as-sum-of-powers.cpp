class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        for (int j = 1; ; j++) {
            int power = pow(j, x);
            if (power > n) break;
            
            for (int i = n; i >= power; i--) {
                dp[i] = (dp[i] + dp[i - power]) % MOD;
            }
        }
        
        return dp[n];
    }
};