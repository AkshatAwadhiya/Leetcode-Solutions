using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int left = 0;
        long long sum = 0;
        int maxFreq = 1;
                for (int right = 0; right < n; right++) {
            sum += nums[right];
                        while ((long long)(right - left + 1) * nums[right] - sum > k) {
                sum -= nums[left];
                left++;
            }
            
            maxFreq = max(maxFreq, right - left + 1);
        }
        
        return maxFreq;
    }
};