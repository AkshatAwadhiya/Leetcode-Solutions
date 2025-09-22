class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }        
        int maxf = 0;
        for (const auto& pair : freq) {
            maxf = max(maxf, pair.second);
        }
        
        int totalCount = 0;
        for (const auto& pair : freq) {
            if (pair.second == maxf) {
                totalCount += pair.second;
            }
        }
        
        return totalCount;
    }
};