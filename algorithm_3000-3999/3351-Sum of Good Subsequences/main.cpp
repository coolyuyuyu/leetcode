class Solution {
public:
    long long M = 1e9+7;
    int sumOfGoodSubsequences(vector<int>& nums) {
        // cnt[num]: the number of good subsequences ending at num
        // sum[num]: the sum of good subsequences ending at num
        unordered_map<int, long long> cnt, sum;
        for (int num : nums) {
            cnt[num] += cnt[num - 1]; cnt[num] %= M;
            cnt[num] += cnt[num + 1]; cnt[num] %= M;
            cnt[num] += 1; cnt[num] %= M;

            sum[num] += sum[num - 1]; sum[num] %= M;
            sum[num] += cnt[num - 1] * num; sum[num] %= M;
            sum[num] += sum[num + 1]; sum[num] %= M;
            sum[num] += cnt[num + 1] * num; sum[num] %= M;
            sum[num] += num; sum[num] %= M;
        }

        long long ret = 0;
        for (const auto& [_, s]: sum) {
            ret += s;
            ret %= M;
        }

        return ret;
    }
};
