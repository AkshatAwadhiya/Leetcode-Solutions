class Solution {
public:
    bool doesAliceWin(string s) {
        int totalVowels = 0;
        for (char c : s) {
            if (isVowel(c)) {
                totalVowels++;
            }
        }       
        return totalVowels > 0;
    }
    
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};