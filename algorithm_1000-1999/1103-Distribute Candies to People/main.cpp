class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n = num_people;
        int lo = 0, hi = ceil(sqrt(candies * 2 / n / n));
        while (lo < hi) {
            int k = hi - (hi - lo) / 2;
            int cnt = (1 +  k * n ) * k * n / 2;
            if (cnt <= candies) {
                lo = k;
            }
            else {
                hi = k - 1;
            }
        }
        int k = lo;

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = (i + 1 + (k - 1) * n + i + 1) * k / 2;
            candies -= ret[i];
        }
        for (int i = 0; i < n && candies; ++i) {
            int cnt = std::min(k * n + i + 1, candies);
            ret[i] += cnt;
            candies -= cnt;
        }

        return ret;
    }
};
