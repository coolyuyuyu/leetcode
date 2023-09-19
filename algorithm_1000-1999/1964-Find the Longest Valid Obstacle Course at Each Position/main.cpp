class Solution {
public:
    // Time: O(n^2)
    vector<int> dp(vector<int>& obstacles) {
        int n = obstacles.size();

        // dp[i]: length of the longest obstacle course from obstacles[0:i] and ending at i
        vector<int> dp(n, 1);
        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (obstacles[j] <= obstacles[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }

            ret[i] = dp[i];
        }

        return ret;
    }

    // Time: O(nlogn)
    vector<int> greedy(vector<int>& obstacles) {
        int n = obstacles.size();

        vector<int> lis; // longest increasing subsequence;
        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            if (lis.empty() || lis.back() <= obstacles[i]) {
                lis.push_back(obstacles[i]);
                ret[i] = lis.size();
            }
            else {
                auto itr = std::upper_bound(lis.begin(), lis.end(), obstacles[i]);
                *itr = obstacles[i];
                ret[i] = std::distance(lis.begin(), itr) + 1;
            }
        }

        return ret;
    }

    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        //return dp(obstacles);
        return greedy(obstacles);
    }
};
