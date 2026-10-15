
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, current, ans);

        return ans;
    }

    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& current, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > target) {
                break;
            }

            current.push_back(candidates[i]);

            backtrack(candidates, target - candidates[i], i + 1,
                      current, ans);

            current.pop_back();
        }
    }
};
