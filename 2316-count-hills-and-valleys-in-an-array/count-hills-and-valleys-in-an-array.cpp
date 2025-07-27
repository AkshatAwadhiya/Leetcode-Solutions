class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 1; i < n - 1; i++) {
            int left = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] != nums[i]) {
                    left = nums[j];
                    break;
                }
            }
            
            int right = -1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] != nums[i]) {
                    right = nums[j];
                    break;
                }
            }
            
            if (left != -1 && right != -1) {
                if ((nums[i] > left && nums[i] > right) || 
                    (nums[i] < left && nums[i] < right)) {
                    
                    if (i == 1 || nums[i] != nums[i-1]) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};