class Solution {
public:
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        int presum[n];
        presum[0] = s[0] == '1';
        for (int i = 1; i < n; ++i) {
            presum[i] = presum[i - 1] + (s[i] == '1');
        }

        std::function<long long(int, int)> f = [&](int l, int r) {
            int n = r - l + 1;
            int cnt = presum[r] - (l > 0 ? presum[l - 1] : 0);
            long long ret = cnt ? (1LL * n * cnt * encCost) : (1LL * flatCost);
            if (n && (n % 2) == 0) {
                ret = std::min(ret, f(l, l + n / 2 - 1) + f(l + n / 2, r));
            }
            return ret;
        };

        return f(0, s.size() - 1);
    }
};
