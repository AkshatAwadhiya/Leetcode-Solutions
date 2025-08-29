class Solution {
public:
    long long flowerGame(int n, int m) {

        long long xn = (n + 1) / 2;
        long long yn = n / 2;
        
        long long xm = (m + 1) / 2;
        long long ym = m / 2;

        return xn * ym + yn * xm;
    }
};