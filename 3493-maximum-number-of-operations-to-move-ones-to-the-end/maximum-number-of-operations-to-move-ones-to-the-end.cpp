class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int ops = 0;
        int ones = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ones++;
            } else {
                if (i > 0 && s[i - 1] == '1') {
                    ops += ones;
                }
            }
        }
        
        return ops;
    }
};