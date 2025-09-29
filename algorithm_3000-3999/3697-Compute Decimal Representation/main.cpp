class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ret;
        for (long base = 1; n; base *= 10, n /= 10) {
            int d = n % 10;
            if (d > 0) {
                ret.push_back(d * base);
            }
        }
        std::reverse(ret.begin(), ret.end());

        return ret;
    }
};
