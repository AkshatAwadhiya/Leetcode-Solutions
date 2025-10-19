class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        queue<string> q;
        
        q.push(s);
        visited.insert(s);
        string result = s;
        
        while (!q.empty()) {
            string current = q.front();
            q.pop();
            
            // Update result if current is lexicographically smaller
            if (current < result) {
                result = current;
            }
            
            // Operation 1: Add 'a' to all odd indices
            string added = addToOddIndices(current, a);
            if (visited.find(added) == visited.end()) {
                visited.insert(added);
                q.push(added);
            }
            
            // Operation 2: Rotate right by 'b' positions
            string rotated = rotateRight(current, b);
            if (visited.find(rotated) == visited.end()) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }
        
        return result;
    }
    
private:
    string addToOddIndices(string s, int a) {
        for (int i = 1; i < s.length(); i += 2) {
            int digit = s[i] - '0';
            digit = (digit + a) % 10;
            s[i] = '0' + digit;
        }
        return s;
    }
    
    string rotateRight(string s, int b) {
        int n = s.length();
        b = b % n;  // Handle cases where b >= n
        return s.substr(n - b) + s.substr(0, n - b);
    }
};