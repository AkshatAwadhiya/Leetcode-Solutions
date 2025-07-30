class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for (int num : nums) {
            if (num > 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }
        vector<int> res;
        int n = pos.size();
        for (int i = 0; i < n; ++i) {
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }
        return res;
    }
};
