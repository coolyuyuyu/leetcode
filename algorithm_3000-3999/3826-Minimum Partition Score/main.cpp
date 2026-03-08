class Solution {
public:

    long long minPartitionScore(vector<int>& nums, int k) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);

        long long presums[n + 1];
        presums[0] = 0;
        for (int i = 1; i <= n; ++i) {
            presums[i] = presums[i - 1] + nums[i];
        }

        long long cache[n + 1][k + 1];
        std::fill(&cache[0][0], &cache[0][0] + (n + 1) * (k + 1), -1);
        std::function<long long(int, int)> f = [&](int i, int k) {
            if (i == 0) {
                return k == 0 ? 0LL : LLONG_MAX / 2;
            }
            else if (k == 0 || i < k) {
                return LLONG_MAX / 2;
            }

            long long& ret = cache[i][k];
            if (ret >= 0) {
                return ret;
            }

            ret = LLONG_MAX;
            for (int j = i; j >= k; --j) {
                long long sum = presums[i] - presums[j - 1];
                long long cost = sum * (sum + 1) / 2;
                if (cost >= ret) {
                    break;
                }
                ret = std::min(ret, f(j - 1, k - 1) + cost);
            }
            return ret;
        };


        return f(n, k);
    }
};
