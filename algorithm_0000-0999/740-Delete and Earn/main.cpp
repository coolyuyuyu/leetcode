class Solution {
public:
    int dp1(const vector<int>& nums) {
        int n = 1e4;

        vector<int> cnts(n + 1, 0);
        for (int num : nums) {
            ++cnts[num];
        }

        // dp[i]: maximum number of points can gain by considering num=1, num=2, ..., num=i
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = cnts[1];
        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 2] + i * cnts[i], dp[i - 1]);
        }

        return dp[n];
    }

    int dp2(const vector<int>& nums) {
        vector<pair<int, int>> pairs; {
            map<int, int> cnts;
            for (int num : nums) {
                ++cnts[num];
            }
            pairs.assign(cnts.begin(), cnts.end());
        }

        int n = pairs.size();
        int delN = 0; // maximum number of points can gain and DONT  delete this
        int delY = pairs[0].first * pairs[0].second; // maximum number of points can gain and DO delete this
        for (int i = 1; i < n; ++i) {
            int tmpN = delN, tmpY = delY;
            if ((pairs[i - 1].first + 1) == pairs[i].first) {
                delN = std::max(tmpN, tmpY);
                delY = tmpN + pairs[i].first * pairs[i].second;
            }
            else {
                delN = std::max(tmpN, tmpY);
                delY = std::max(tmpN, tmpY) + pairs[i].first * pairs[i].second;
            }
        }

        return std::max(delN, delY);
    }

    int deleteAndEarn(vector<int>& nums) {
        //return dp1(nums);
        return dp2(nums);
    }
};
