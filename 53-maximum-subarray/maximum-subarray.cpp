class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];        
        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }    
        return maxSum;
    }    
    int maxSubArrayDivideConquer(vector<int>& nums) {
        return divideConquer(nums, 0, nums.size() - 1);
    }
    
private:
    int divideConquer(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        
        int mid = left + (right - left) / 2;
        int leftMax = divideConquer(nums, left, mid);
        int rightMax = divideConquer(nums, mid + 1, right);
        int crossMax = maxCrossingSum(nums, left, mid, right);
        return max({leftMax, rightMax, crossMax});
    }
    int maxCrossingSum(vector<int>& nums, int left, int mid, int right) {
        int leftSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        int rightSum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }        
        return leftSum + rightSum;
    }
};
class SolutionAlternative {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEndingHere = 0;
        int maxSoFar = INT_MIN;
        
        for (int num : nums) {
            maxEndingHere = maxEndingHere + num;
            maxSoFar = max(maxSoFar, maxEndingHere);
            
            if (maxEndingHere < 0) {
                maxEndingHere = 0;
            }
        }
        
        return maxSoFar;
    }
};