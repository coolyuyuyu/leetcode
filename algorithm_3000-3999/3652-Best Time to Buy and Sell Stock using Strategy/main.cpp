class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        long long presumPrice[n];
        long long presumProfit[n];
        for (int i = 0; i < n; ++i) {
            presumPrice[i] = (i > 0 ? presumPrice[i - 1] : 0) + prices[i];
            presumProfit[i] = (i > 0 ? presumProfit[i - 1] : 0) + prices[i] * strategy[i];
        }

        long long ret = presumProfit[n - 1];
        for (int i = 0; i + k <= n; ++i) {
            long long tmp = presumProfit[n - 1], l, r;
            l = i, r = i + k - 1;
            tmp -= (presumProfit[r] - (l > 0 ? presumProfit[l - 1] : 0));
            l = i + k / 2, r = i + k - 1;
            tmp += (presumPrice[r] - (l > 0 ? presumPrice[l - 1] : 0));

            ret = std::max(ret, tmp);
        }

        return ret;
    }
};
