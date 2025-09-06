class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int totalBeauty = 0;
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                
                int beauty = calculatebeauty(freq);
                totalBeauty += beauty;
            }
        }
        
        return totalBeauty;
    }
    
private:
    int calculatebeauty(vector<int>& freq) {
        int maxFreq = 0;
        int minFreq = INT_MAX;
        
        for (int count : freq) {
            if (count > 0) {
                maxFreq = max(maxFreq, count);
                minFreq = min(minFreq, count);
            }
        }
        
        if (minFreq == INT_MAX) {
            return 0;
        }
        
        return maxFreq - minFreq;
    }
};