class Solution {
public:
    int maxFreqSum(string s) {
        array<int, 26> freq{};
        for (char c : s) freq[c - 'a']++;
        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        int maxV = 0, maxC = 0;
        for (char v : string("aeiou")) {
            maxV = max(maxV, freq[v - 'a']);
        }
        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            if (isVowel(ch)) continue;
            maxC = max(maxC, freq[i]);
        }

        return maxV + maxC;
    }
};