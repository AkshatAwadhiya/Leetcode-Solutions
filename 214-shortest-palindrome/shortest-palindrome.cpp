class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        string combined = s + "#" + rev;
        
        vector<int> lps = LPS(combined);
        int overlap = lps.back();        
        string toAdd = rev.substr(0, s.length() - overlap);
        
        return toAdd + s;
    }
    
private:
    vector<int> LPS(const string& pattern) {
        int n = pattern.length();
        vector<int> lps(n, 0);
        int len = 0;
        int i = 1;
        
        while (i < n) {
            if (pattern[i] == pattern[len]) {
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
        
        return lps;
    }
};