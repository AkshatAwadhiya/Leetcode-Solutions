class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());       
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (finish(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool finish(vector<int>& piles, int speed, int h) {
        long long totalHours = 0;        
        for (int pile : piles) {
            totalHours += (pile + speed - 1) / speed;            
            if (totalHours > h) {
                return false;
            }
        }
        
        return totalHours <= h;
    }
};