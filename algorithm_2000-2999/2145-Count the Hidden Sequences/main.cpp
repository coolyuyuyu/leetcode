class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mn = 0, mx = 0;
        for (long long i = 0, n = differences.size(), num = 0; i < n; ++i) {
            num += differences[i];
            mn = std::min(mn, num);
            mx = std::max(mx, num);
        }

        return std::max((upper - lower) - (mx - mn) + 1, 0LL);
    }
};
