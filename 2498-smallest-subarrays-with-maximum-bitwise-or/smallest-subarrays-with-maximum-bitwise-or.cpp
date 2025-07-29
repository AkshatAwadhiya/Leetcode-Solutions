class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> bit_last_pos(30, -1);

        for (int i = n - 1; i >= 0; --i) {
            for (int b = 0; b < 30; ++b) {
                if (nums[i] & (1 << b)) {
                    bit_last_pos[b] = i;
                }
            }
            int farthest = i;
            for (int b = 0; b < 30; ++b) {
                if (bit_last_pos[b] != -1) {
                    farthest = max(farthest, bit_last_pos[b]);
                }
            }
            ans[i] = farthest - i + 1;
        }
        return ans;
    }
};
