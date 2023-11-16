class Solution {
public:
    // Time: O(nlogk)
    int byMultiSet(vector<int>& nums, int k) {
        int n = nums.size();

        multiset<int> ms;

        // dp[i]: the maximum sum of a non-empty subsequence of nums[0:i] and ending at nums[i]
        int dp[n];
        for (int i = 0; i < n; ++i) {
            if (i - k - 1 >= 0) {
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

        deque<int> dq;

        // dp[i]: the maximum sum of a non-empty subsequence of nums[0:i] and ending at nums[i]
        int dp[n];
        for (int i = 0; i < n; ++i) {
            if (!dq.empty() && i - k - 1 == dq.front()) {
                dq.pop_front();
            }

            dp[i] = nums[i];
            if (!dq.empty()) {
                dp[i] = std::max(dp[i], dp[i] + dp[dq.front()]);
            }

            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        int ret = INT_MIN;
        for (int i = 0; i < n; ++i) {
            ret = std::max(ret, dp[i]);
        }

        return ret;
    }

    int constrainedSubsetSum(vector<int>& nums, int k) {
        //return byMultiSet(nums, k);
        return byDeque(nums, k);
    }
};
