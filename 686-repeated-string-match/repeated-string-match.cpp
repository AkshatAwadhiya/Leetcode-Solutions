class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        unordered_set<char> chars(a.begin(), a.end());
        for (char c : b) {
            if (chars.find(c) == chars.end()) {
                return -1;
            }
        }

        int min = (b.length() + a.length() - 1) / a.length();
        for (int repeats = min; repeats <= min + 1; repeats++) {
            string repeated = "";
            for (int i = 0; i < repeats; i++) {
                repeated += a;
            }
            
            if (repeated.find(b) != string::npos) {
                return repeats;
            }
        }
        
        return -1;
    }
};