class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            return helper(s, 'b', 'a', y) + helper(s, 'a', 'b', x);
        } else {
            return helper(s, 'a', 'b', x) + helper(s, 'b', 'a', y);
        }
    }    
private:
    int helper(string& s, char first, char second, int points) {
        int score = 0;
        int writeIndex = 0;        
        for (int readIndex = 0; readIndex < s.length(); readIndex++) {
            s[writeIndex] = s[readIndex];            
            if (writeIndex > 0 && s[writeIndex - 1] == first && s[writeIndex] == second) {
                score += points;
                writeIndex -= 2;
            }
            writeIndex++;
        }
        s.resize(writeIndex);
        return score;
    }
};