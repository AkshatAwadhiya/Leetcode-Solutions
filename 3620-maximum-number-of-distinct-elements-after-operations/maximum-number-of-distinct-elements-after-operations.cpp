class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int distinctCount = 0;
        long long lastAssigned = LLONG_MIN;
        
        for (int num : nums) {
            long long minVal = (long long)num - k;
            long long maxVal = (long long)num + k;
            

            long long target = max(minVal, lastAssigned + 1);
            
            if (target <= maxVal) {
                distinctCount++;
                lastAssigned = target;
            }

        }
        
        return distinctCount;
    }
};