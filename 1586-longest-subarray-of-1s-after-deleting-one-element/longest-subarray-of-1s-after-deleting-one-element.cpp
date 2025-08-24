class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int zerocount = 0;
        int maxlen = 0;        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                zerocount++;
            }            
            while (zerocount > 1) {
                if (nums[left] == 0) {
                    zerocount--;
                }
                left++;
            }            
            maxlen = max(maxlen, right - left + 1 - 1);
        }        
        return maxlen;
    }
};