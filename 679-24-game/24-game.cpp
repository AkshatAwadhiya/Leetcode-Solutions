class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int card : cards) {
            nums.push_back((double)card);
        }
        return solve(nums);
    }
    
private:
    bool solve(vector<double>& nums) {
        int n = nums.size();
        
        if (n == 1) {
            return abs(nums[0] - 24.0) < 1e-6;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double a = nums[i];
                double b = nums[j];
                
                vector<double> remaining;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) {
                        remaining.push_back(nums[k]);
                    }
                }
                
                vector<double> results = {
                    a + b,    
                    a - b,    
                    b - a,   
                    a * b 
                };
                
                if (abs(b) > 1e-6) {
                    results.push_back(a / b);
                }
                if (abs(a) > 1e-6) {
                    results.push_back(b / a);
                }
                
                for (double result : results) {
                    vector<double> newNums = remaining;
                    newNums.push_back(result);
                    
                    if (solve(newNums)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};