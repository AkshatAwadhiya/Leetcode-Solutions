
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> sorted;
        for (int num : nums) {
            sorted.push_back({num, digitSum(num)});
        }

        sort(sorted.begin(), sorted.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.second != b.second)
                     return a.second < b.second;
                 return a.first < b.first;
             });

        unordered_map<int, int> targetIndex;
        for (int i = 0; i < n; i++) {
            targetIndex[sorted[i].first] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || targetIndex[nums[i]] == i)
                continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = targetIndex[nums[j]];
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};
