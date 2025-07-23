class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorResult = 0;        
        for (int i = 0; i <= n; i++) {
            xorResult ^= i;
        }        
        for (int num : nums) {
            xorResult ^= num;
        }        
        return xorResult;
    }    
    int missingNumberConcise(vector<int>& nums) {
        int n = nums.size();
        int xorResult = n;
        
        for (int i = 0; i < n; i++) {
            xorResult ^= i ^ nums[i];
        }        
        return xorResult;
    }    
    int missingNumberSum(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;        
        for (int num : nums) {
            actualSum += num;
        }        
        return expectedSum - actualSum;
    }
};