class Solution {
public:
    int totalMoney(int n) {
        int w = n / 7;
        int d = n % 7;

        int ret = (28 + 28 + (w - 1) * 7) * w / 2; 
        ret += (w + 1 + w + 1 + (d - 1)) * d / 2;
        return ret;
    }
};
