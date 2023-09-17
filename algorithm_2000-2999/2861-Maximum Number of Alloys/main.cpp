class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        std::function<bool(long long)> isOk = [&](long long numAlloy) -> bool {
            for (int i = 0; i < k; ++i) {
                long long totalCost = 0;
                for (int j = 0; j < n; ++j) {
                    totalCost += (std::max(0LL, numAlloy * composition[i][j] - stock[j])) * cost[j];
                }
                if (totalCost <= budget) {
                    return true;
                }
            }

            return false;
        };

        int lo = 0, hi = 2 * 1e8;
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (isOk(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
