class Solution {
public:
    long long maxScore(vector<int>& prices) {
        // prices[indexes[j]] - prices[indexes[j - 1]] == indexes[j] - indexes[j - 1]
        // => prices[indexes[j]] - indexes[j] == prices[indexes[j - 1]] - indexes[j - 1]

        unordered_map<int, long long> sums;

        int n = prices.size();
        for (int i = 0; i < n; ++i) {
            sums[prices[i] - i] += prices[i];
        }

        long long ret = 0;
        for (const auto& [_, sum] : sums) {
            ret = std::max(ret, sum);
        }

        return ret;
    }
};
