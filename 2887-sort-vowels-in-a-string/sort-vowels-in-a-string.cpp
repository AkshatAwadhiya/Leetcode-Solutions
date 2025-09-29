class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }
        
        sort(vowels.begin(), vowels.end());
        string result = s;
        int vowelIndex = 0;
        
        for (int i = 0; i < result.length(); i++) {
            if (isVowel(result[i])) {
                result[i] = vowels[vowelIndex++];
            }
        }
        
        return result;
    }
    
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};