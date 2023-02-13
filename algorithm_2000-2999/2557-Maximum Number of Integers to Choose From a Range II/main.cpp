class Solution {
public:
    bool exceed(int n, const vector<int>& banned, const vector<long long>& presum, long long maxSum) {
        long long sum = static_cast<long long>(n) * (1 + n) / 2;
        size_t index = std::distance(banned.begin(), std::upper_bound(banned.begin(), banned.end(), n));
        sum -= index == 0 ? 0 : presum[index - 1];
        return maxSum < sum;
    }

    int maxCount(vector<int>& banned, int n, long long maxSum) {
        std::sort(banned.begin(), banned.end());

        vector<long long> presum(banned.size());
        for (size_t i = 0; i < presum.size(); ++i) {
            presum[i] = banned[i];
        }
        std::partial_sum(presum.begin(), presum.end(), presum.begin());

        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (exceed(mid, banned, presum, maxSum)) {
                hi = mid - 1;
            }
            else {
                lo = mid;
            }
        }

        return lo - std::distance(banned.begin(), std::upper_bound(banned.begin(), banned.end(), lo));
    }
};
