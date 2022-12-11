class Solution {
public:
    // dp, Time: O(n)
    int longestSquareStreak(vector<int>& nums) {
        map<int, int> dp;
        for (int num : nums) {
            dp[num] = 1;
        }

        int ret = -1;
        for (auto& p : dp) {
            int root = sqrt(p.first);
            if (p.first == root * root) {
                p.second = dp[root] + 1;
            }

            ret = std::max(ret, p.second);
        }

        return ret <= 1 ? -1 : ret;;
    }
};
