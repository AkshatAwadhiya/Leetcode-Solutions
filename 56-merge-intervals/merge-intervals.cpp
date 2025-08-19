class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};        
        sort(intervals.begin(), intervals.end());        
        vector<vector<int>> result;
        result.push_back(intervals[0]);        
        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& lastInterval = result.back();
            vector<int>& currentInterval = intervals[i];            
            if (currentInterval[0] <= lastInterval[1]) {
                lastInterval[1] = max(lastInterval[1], currentInterval[1]);
            } else {
                result.push_back(currentInterval);
            }
        }        
        return result;
    }
};