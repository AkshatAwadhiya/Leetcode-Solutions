class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;        
        vector<long long> minSumFirst(n + 1);
        vector<long long> maxSumSecond(n + 1);
        
        priority_queue<int> maxHeap;
        long long sum = 0;
        
        for (int i = 0; i < n; i++) {
            maxHeap.push(nums[i]);
            sum += nums[i];
        }
        minSumFirst[0] = sum;
        
        for (int i = n; i < 2 * n; i++) {
            maxHeap.push(nums[i]);
            sum += nums[i];
            sum -= maxHeap.top();
            maxHeap.pop();
            minSumFirst[i - n + 1] = sum;
        }
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;
        
        for (int i = 2 * n; i < 3 * n; i++) {
            minHeap.push(nums[i]);
            sum += nums[i];
        }
        maxSumSecond[n] = sum;
        
        for (int i = 2 * n - 1; i >= n; i--) {
            minHeap.push(nums[i]);
            sum += nums[i];
            sum -= minHeap.top();
            minHeap.pop();
            maxSumSecond[i - n] = sum;
        }
        
        long long minDiff = LLONG_MAX;
        for (int i = 0; i <= n; i++) {
            minDiff = min(minDiff, minSumFirst[i] - maxSumSecond[i]);
        }
        
        return minDiff;
    }
};