class Solution {
public:
    // Time: O(n * logk)
    int byMultiset(vector<int>& nums, int k) {
        int n = nums.size();

        multiset<int> ms;

        // dp[i]: the maximum sum of a non-empty subsequence ending at nums[i]
        int dp[n];
        for (int i = 0; i < n; ++i) {
            if (ms.size() > k) {
                ms.erase(ms.find(dp[i - k - 1]));
            }

            dp[i] = nums[i];
            if (!ms.empty()) {
                dp[i] = std::max(dp[i], dp[i] + *ms.rbegin());
            }

            ms.insert(dp[i]);
        }

        int ret = INT_MIN;
        for (int i = 0; i < n; ++i) {
            ret = std::max(ret, dp[i]);
        }

        return ret;
    }

    // Time: O(n)
    int byDeque(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> q;

        // dp[i]: the maximum sum of a non-empty subsequence ending at nums[i]
        int dp[n];
        for (int i = 0; i < n; ++i) {
            if (!q.empty() && i - q.front() > k) {
                q.pop_front();
            }

            dp[i] = nums[i];
            if (!q.empty()) {
                dp[i] = std::max(dp[i], dp[i] + dp[q.front()]);
            }

            while (!q.empty() && dp[q.back()] <= dp[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        int ret = INT_MIN;
        for (int i = 0; i < n; ++i) {
            ret = std::max(ret, dp[i]);
        }

        return ret;
    }

    int constrainedSubsetSum(vector<int>& nums, int k) {
        //return byMultiset(nums, k);
        return byDeque(nums, k);
    }
};
