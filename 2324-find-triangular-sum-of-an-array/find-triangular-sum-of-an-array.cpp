class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> newNums;            
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = (nums[i] + nums[i + 1]) % 10;
                newNums.push_back(sum);
            }            
            nums = newNums;
        }        
        return nums[0];
    }
};