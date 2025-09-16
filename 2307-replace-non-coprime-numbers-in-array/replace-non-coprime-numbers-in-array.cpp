class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st;
        for (int v : nums) {
            long long x = v;
            while (!st.empty()) {
                long long g = std::gcd(st.back(), x);
                if (g == 1) break;
                x = (st.back() / g) * x;
                st.pop_back();
            }
            st.push_back(x);
        }
        vector<int> ans;
        ans.reserve(st.size());
        for (auto z : st) ans.push_back((int)z);
        return ans;
    }
};
