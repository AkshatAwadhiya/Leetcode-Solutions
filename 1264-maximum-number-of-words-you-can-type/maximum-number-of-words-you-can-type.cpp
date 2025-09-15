class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());        
        int count = 0;
        int i = 0;
        int n = text.length();        
        while (i < n) {
            bool canType = true;            
            while (i < n && text[i] != ' ') {
                if (broken.find(text[i]) != broken.end()) {
                    canType = false;
                }
                i++;
            }            
            if (canType) {
                count++;
            }            
            if (i < n && text[i] == ' ') {
                i++;
            }
        }
        
        return count;
    }
};