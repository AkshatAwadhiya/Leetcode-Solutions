class Solution {
public:
    string largestGoodInteger(string num) {
        string result = "";
        
        for (int i = 0; i <= (int)num.length() - 3; i++) {
            string current = num.substr(i, 3);            
            if (current[0] == current[1] && current[1] == current[2]) {
                if (current > result) {
                    result = current;
                }
            }
        }
        
        return result;
    }
};