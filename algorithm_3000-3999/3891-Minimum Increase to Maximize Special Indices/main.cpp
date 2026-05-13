
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        std::function<pair<int, long long>(const pair<int, long long>&, const pair<int, long long>&)> minPair = [](const pair<int, long long>& p1, const pair<int, long long>& p2) {
            const auto& [cnt1, cost1] = p1;
            const auto& [cnt2, cost2] = p2;
            if (cnt1 > cnt2) {
                return p1;
            }
            else if (cnt1 == cnt2) {
                return make_pair(cnt1, std::min(cost1, cost2));
            }
            else {
                return p2;
            }
            return p1;
        };

        // dp[i][0]: {cnt, cost}, maxmimal number of spical indices from num[0:i] and nums[i] is peak, where cost is minimized.
        // dp[i][1]: {cnt, cost}, maxmimal number of spical indices from num[0:i] and nums[i] is MPT peak, where cost is minimized.
        pair<int, long long> dp0 = {0, 0}, dp1 = {0, LLONG_MAX};
        for (int i = 1; i + 1 < nums.size(); ++i) {
            pair<int, long long> tmp0 = dp0, tmp1 = dp1;

            dp0 = minPair(tmp0, tmp1);
            dp1 = {tmp0.first + 1, tmp0.second + std::max(0, std::max(nums[i - 1], nums[i + 1]) + 1 - nums[i])};
        }

        return minPair(dp0, dp1).second;
    }
};
