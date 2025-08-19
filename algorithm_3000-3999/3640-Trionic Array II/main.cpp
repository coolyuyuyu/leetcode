class Solution {
public:
    vector<pair<int, int>> findDecreasing(vector<int>& nums) {
        vector<pair<int, int>> ret;
        for (int p = 0, n = nums.size(); p < n;) {
            int q = p;
            while (q + 1 < n && nums[q] > nums[q + 1]) {
                ++q;
            }
            if (p < q) {
                ret.emplace_back(p, q);
            }
            p = q + 1;
        }

        return ret;
    }

    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();

        long long ret = LLONG_MIN;
        for (auto [p, q] : findDecreasing(nums)) {
            if (!(p > 0 && nums[p - 1] < nums[p])) { continue; }
            if (!(q + 1 < n && nums[q] < nums[q + 1])) { continue; }

            long long sum;

            long long lftSum = LLONG_MIN;
            sum = 0;
            for (int l = p - 1; l >= 0 && nums[l] < nums[l + 1]; --l) {
                sum += nums[l];
                lftSum = std::max(lftSum, sum);
            }

            long long rhtSum = LLONG_MIN;
            sum = 0;
            for (int r = q + 1; r < n && nums[r - 1] < nums[r]; ++r) {
                sum += nums[r];
                rhtSum = std::max(rhtSum, sum);
            }

            ret = std::max(ret, lftSum + rhtSum + std::accumulate(nums.begin() + p, nums.begin() + q + 1, 0LL));
        }

        return ret;
    }
};
