class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq({0});

        // dp[i] the maximum score you can get when you reach i
        int dp[n];
        dp[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            if (!dq.empty() && dq.front() == i - k - 1) {
                dq.pop_front();
            }

            dp[i] = dp[dq.front()] + nums[i];

            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return dp[n - 1];
    }
};
