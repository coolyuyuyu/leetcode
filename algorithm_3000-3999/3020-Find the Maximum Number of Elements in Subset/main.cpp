class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int, int> cnts;
        int cnt1 = 0;
        for (int num : nums) {
            if (num == 1) { ++cnt1; }
            else { ++cnts[num]; }
        }
        int ret = cnt1 ? (cnt1 & 1 ? cnt1 : cnt1 - 1) : 0;

        // dp[num]: the maximum number of elements in a subset and the max element is num
        unordered_map<int, int> dp;

        for (const auto [cur, cnt] : cnts) {
            dp[cur] = 1;
            int pre = std::sqrt(cur);
            if (pre * pre == cur) {
                auto itr = cnts.find(pre);
                if (itr != cnts.end() && itr->second >= 2) {
                    dp[cur] = dp[pre] + 2;
                }
            }

            ret = std::max(ret, dp[cur]);
        }

        return ret;
    }
};
