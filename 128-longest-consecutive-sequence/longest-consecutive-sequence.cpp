class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for (int num : s) {
            if (!s.count(num - 1)) {
                int curr = num, streak = 1;
                while (s.count(curr + 1)) {
                    curr++;
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};
