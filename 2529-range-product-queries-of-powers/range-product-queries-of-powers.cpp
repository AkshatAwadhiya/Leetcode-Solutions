class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        
        vector<int> powers;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                powers.push_back(i);
            }
        }
        
        vector<int> answers;
        for (auto& query : queries) {
            int left = query[0];
            int right = query[1];
            
            long long totalExponent = 0;
            for (int i = left; i <= right; i++) {
                totalExponent += powers[i];
            }
            
            long long result = modPow(2, totalExponent, MOD);
            answers.push_back(result);
        }
        
        return answers;
    }
    
private:
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        
        return result;
    }
};