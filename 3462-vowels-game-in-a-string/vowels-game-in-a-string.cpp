class Solution {
public:
    bool doesAliceWin(string s) {
        int total = 0;
        for (char c : s) {
            if (isvowel(c)) {
                total++;
            }
        }       
        return total > 0;
    }
    
private:
    bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};