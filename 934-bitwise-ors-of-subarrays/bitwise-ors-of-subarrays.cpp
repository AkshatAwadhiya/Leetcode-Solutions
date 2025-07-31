class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans, cur, next;
        for (int num : arr) {
            next = {num};
            for (int x : cur)
                next.insert(x | num);
            cur = next;
            ans.insert(cur.begin(), cur.end());
        }
        return ans.size();
    }
};
