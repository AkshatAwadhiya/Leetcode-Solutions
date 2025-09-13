class Solution {
public:
    int maxFreqSum(string s) {
        array<int, 26> freq{};
        for (char c : s) freq[c - 'a']++;
        auto vowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        int maxX = 0, maxY = 0;
        for (char v : string("aeiou")) {
            maxX = max(maxX, freq[v - 'a']);
        }
        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            if (vowel(ch)) continue;
            maxY = max(maxY, freq[i]);
        }

        return maxX + maxY;
    }
};