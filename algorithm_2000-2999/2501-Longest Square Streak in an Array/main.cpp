class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // dp[i]: length of the longest square streak ending at i
        map<int, int> dp;
        for (int num : nums) {
            dp[num] = 1;
        }

        int ret = 0;
        for (auto& [curNum, curLen] : dp) {
            auto itr = dp.find(std::sqrt(curNum));
            if (itr != dp.end()) {
                const auto& [preNum, preLen] = *itr;
                if (preNum * preNum == curNum) {
                    curLen = preLen + 1;
                }
            }

            ret = std::max(ret, curLen);
        }

        return ret > 1 ? ret : -1;
    }
};
