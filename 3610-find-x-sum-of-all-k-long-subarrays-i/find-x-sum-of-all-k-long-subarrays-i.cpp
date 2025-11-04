class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> answer;

        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }
            
            vector<pair<int, int>> elements;
            for (auto& [num, count] : freq) {
                elements.push_back({num, count});
            }
            
            sort(elements.begin(), elements.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.second != b.second) {
                    return a.second > b.second;
                }
                return a.first > b.first;
            });
            
            int xSum = 0;
            int topX = min(x, (int)elements.size());
            
            for (int j = 0; j < topX; j++) {
                int element = elements[j].first;
                int count = elements[j].second;
                xSum += element * count;
            }
            
            answer.push_back(xSum);
        }
        
        return answer;
    }
};