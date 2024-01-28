class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int cnt1 = 0;
        map<int, int> cnts;
        for (int num : nums) {
            if (num == 1) {
                ++cnt1;
            }
            else {
                ++cnts[num];
            }
        }
        int ret = cnt1 ? (cnt1 & 1 ? cnt1 : cnt1 - 1) : 0;

        // dp[x]: the selected elements follows the pattern, and the max element is x
        map<int, int> dp;
        for (const auto& [x, cnt] : cnts) {
            int y = std::sqrt(x);
            if (y * y == x && cnts.find(y) != cnts.end() && cnts[y] >= 2) {
                dp[x] = dp[y] + 2;
            }
            else {
                dp[x] = 1;
            }

            ret = std::max(ret, dp[x]);
        }

        return ret;
    }
};
