class Solution {
public:
    int minDays(vector<int>& bloomday, int m, int k) {
        if ((long long)m * k > bloomday.size()) {
            return -1;
        }       
        int left = *min_element(bloomday.begin(), bloomday.end());
        int right = *max_element(bloomday.begin(), bloomday.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canMakeBouquets(bloomday, mid, m, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canMakeBouquets(vector<int>& bloomday, int day, int m, int k) {
        int bouquets = 0;
        int consecutiveFlowers = 0;
        
        for (int i = 0; i < bloomday.size(); i++) {
            if (bloomday[i] <= day) {
                consecutiveFlowers++;
                
                if (consecutiveFlowers == k) {
                    bouquets++;
                    consecutiveFlowers = 0;
                }
            } else {
                consecutiveFlowers = 0;
            }
        }
        
        return bouquets >= m;
    }
};