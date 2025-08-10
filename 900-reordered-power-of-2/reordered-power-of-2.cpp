class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string target = to_string(n);
        sort(target.begin(), target.end());
        
        for (int i = 0; i < 30; i++) {
            string powerStr = to_string(1 << i);
            sort(powerStr.begin(), powerStr.end());
            
            if (target == powerStr) {
                return true;
            }
        }
        
        return false;
    }
};