class Solution {
public:    
    string reverseWords(string s) {
        vector<string> words;
        int i = 0;
        int n = s.length();
        
        while (i < n) {
            while (i < n && s[i] == ' ') {
                i++;
            }
            
            if (i < n) {
                string word = "";
                while (i < n && s[i] != ' ') {
                    word += s[i];
                    i++;
                }
                words.push_back(word);
            }
        }
        
        string result = "";
        for (int j = words.size() - 1; j >= 0; j--) {
            result += words[j];
            if (j > 0) {
                result += " ";
            }
        }
        
        return result;
    }
};