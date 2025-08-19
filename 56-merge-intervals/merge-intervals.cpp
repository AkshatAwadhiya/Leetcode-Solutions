class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        if (interval.empty()) return {};        
        sort(interval.begin(), interval.end());        
        vector<vector<int>> result;
        result.push_back(interval[0]);        
        for (int i = 1; i < interval.size(); i++) {
            vector<int>& lastInterval = result.back();
            vector<int>& currentInterval = interval[i];            
            if (currentInterval[0] <= lastInterval[1]) {
                lastInterval[1] = max(lastInterval[1], currentInterval[1]);
            } else {
                result.push_back(currentInterval);
            }
        }        
        return result;
    }
};