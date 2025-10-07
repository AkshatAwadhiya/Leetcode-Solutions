class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> result(n);
        
        unordered_map<int, int> fullLakes;        
        set<int> dryDays;
        
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dryDays.insert(i);
                result[i] = 1;
            } else {
                int lake = rains[i];
                result[i] = -1;                
                if (fullLakes.count(lake)) {
                    int filledDay = fullLakes[lake];
                    
                    auto it = dryDays.upper_bound(filledDay);
                    
                    if (it == dryDays.end()) {
                        return {};
                    }
                    int dryDay = *it;
                    result[dryDay] = lake;
                    dryDays.erase(it);
                    fullLakes.erase(lake);
                }                
                fullLakes[lake] = i;
            }
        }
        
        return result;
    }
};