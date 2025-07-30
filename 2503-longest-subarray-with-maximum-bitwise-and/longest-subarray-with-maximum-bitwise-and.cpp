class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int maxLen = 0, currLen = 0;
        for (int num : nums) {
            if (num == maxVal) {
                currLen++;
                maxLen = max(maxLen, currLen);
            } else {
                currLen = 0;
            }
        }
        return maxLen;
    }
};
