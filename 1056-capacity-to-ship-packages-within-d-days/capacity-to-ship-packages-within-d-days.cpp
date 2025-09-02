class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = 0;
        for (int weight : weights) {
            right += weight;
        }
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canShipInDays(weights, mid, days)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canShipInDays(vector<int>& weights, int capacity, int days) {
        int daysUsed = 1;
        int currentWeight = 0;
        
        for (int weight : weights) {
            if (currentWeight + weight > capacity) {
                daysUsed++;
                currentWeight = weight;
                
                if (daysUsed > days) {
                    return false;
                }
            } else {
                currentWeight += weight;
            }
        }
        
        return true;
    }
};