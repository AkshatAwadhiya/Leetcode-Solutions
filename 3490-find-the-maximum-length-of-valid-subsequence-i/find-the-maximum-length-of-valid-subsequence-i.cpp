class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        
        int allEven = 0;
        for (int num : nums) {
            if (num % 2 == 0) allEven++;
        }
        
        int allOdd = 0;
        for (int num : nums) {
            if (num % 2 == 1) allOdd++;
        }
        
        int evenOdd = 0;
        int expectEven = 1;
        for (int num : nums) {
            if ((num % 2 == 0 && expectEven) || (num % 2 == 1 && !expectEven)) {
                evenOdd++;
                expectEven = !expectEven;
            }
        }
        
        int oddEven = 0;
        int expectOdd = 1;
        for (int num : nums) {
            if ((num % 2 == 1 && expectOdd) || (num % 2 == 0 && !expectOdd)) {
                oddEven++;
                expectOdd = !expectOdd;
            }
        }
        
        return max({allEven, allOdd, evenOdd, oddEven});
    }
};