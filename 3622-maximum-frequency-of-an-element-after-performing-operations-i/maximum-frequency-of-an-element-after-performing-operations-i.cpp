class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());        
        unordered_map<int, int> originalCount;
        for (int num : nums) {
            originalCount[num]++;
        }
        
        int maxFreq = 0;        
        unordered_set<int> targets(nums.begin(), nums.end());        
        for (int num : nums) {
            targets.insert(num - k);
            targets.insert(num + k);
        }
        
        for (int target : targets) {
            int alreadyEqual = originalCount[target];
            
            int canTransform = 0;
            
            auto left = lower_bound(nums.begin(), nums.end(), target - k);
            auto right = upper_bound(nums.begin(), nums.end(), target + k);
            
            int inRange = right - left;
            canTransform = inRange - alreadyEqual;            
            int transformed = min(canTransform, numOperations);            
            maxFreq = max(maxFreq, alreadyEqual + transformed);
        }
        
        return maxFreq;
    }
};