class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;        
        int prefixSum = 0, result = 0;        
        for (int num : nums) {
            prefixSum += num;            
            result += prefixSumCount[prefixSum - k];            
            prefixSumCount[prefixSum]++;
        }       
        return result;
    }
};