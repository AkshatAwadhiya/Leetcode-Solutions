class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        if(n<1) return "";
        vector<int> lps(n,0);
        int len = 0;
        int i = 1;

        while  (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        int happyPrefixLength = lps[n - 1];        
        return happyPrefixLength == 0 ? "" : s.substr(0, happyPrefixLength);
    }
};