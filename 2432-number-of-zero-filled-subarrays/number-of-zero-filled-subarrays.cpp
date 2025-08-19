class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        long long currentZeroCount = 0;
        
        for (int num : nums) {
            if (num == 0) {
                currentZeroCount++;
            } else {
                if (currentZeroCount > 0) {
                    result += currentZeroCount * (currentZeroCount + 1) / 2;
                    currentZeroCount = 0;
                }
            }
        }        
        if (currentZeroCount > 0) {
            result += currentZeroCount * (currentZeroCount + 1) / 2;
        }
        
        return result;
    }
};