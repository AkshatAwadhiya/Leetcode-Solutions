class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1000000007;
        
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        
        for (int day = 1; day <= n; day++) {
            if (dp[day] == 0) continue;
            
            for (int shareDay = day + delay; shareDay < day + forget && shareDay <= n; shareDay++) {
                dp[shareDay] = (dp[shareDay] + dp[day]) % MOD;
            }
        }
        
        long long result = 0;
        for (int learnDay = 1; learnDay <= n; learnDay++) {
            if (learnDay + forget > n) {
                result = (result + dp[learnDay]) % MOD;
            }
        }
        
        return result;
    }
};