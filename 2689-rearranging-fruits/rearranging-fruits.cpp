class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> count;
        
        for (int fruit : basket1) {
            count[fruit]++;
        }
        for (int fruit : basket2) {
            count[fruit]--;
        }
        
        for (auto& [fruit, freq] : count) {
            if (freq % 2 != 0) {
                return -1;
            }
        }
        
        vector<int> needFromBasket1, needFromBasket2;
        
        for (auto& [fruit, freq] : count) {
            int halfDiff = abs(freq) / 2;
            for (int i = 0; i < halfDiff; i++) {
                if (freq > 0) {
                    needFromBasket1.push_back(fruit);
                } else {
                    needFromBasket2.push_back(fruit);
                }
            }
        }        
        sort(needFromBasket1.begin(), needFromBasket1.end());
        sort(needFromBasket2.begin(), needFromBasket2.end(), greater<int>());
        
        long long totalCost = 0;
        int minFruit = INT_MAX;        
        for (int fruit : basket1) {
            minFruit = min(minFruit, fruit);
        }
        for (int fruit : basket2) {
            minFruit = min(minFruit, fruit);
        }        
        for (int i = 0; i < needFromBasket1.size(); i++) {
            int directSwapCost = min(needFromBasket1[i], needFromBasket2[i]);
            int doubleSwapCost = 2 * minFruit;
            totalCost += min(directSwapCost, doubleSwapCost);
        }
        
        return totalCost;
    }
};