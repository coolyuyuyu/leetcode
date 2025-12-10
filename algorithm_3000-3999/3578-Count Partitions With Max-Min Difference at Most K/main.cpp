class Solution {
public:
    int M = 1e9 + 7;

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        // dp[i]: the total number of ways to partition nums[1:i].
        int dp[n + 1];

        // X X X X X X X
        //         j   i
        // j: the smallest index to form nums[i:j] a valid partition
        // dp[i] = dp[j - 1] + ... dp[i - 1]

        // presums[i]: sum of dp[1:i]
        // dp[i] = presums[i - 1] - presums[j - 2]

        int presums[n + 1];

        deque<int> dqMax, dqMin;

        dp[0] = 1;
        presums[0] = dp[0];
        for (int i = 1, j = 1; i <= n; ++i) {
            while (!dqMax.empty() && nums[dqMax.back()] < nums[i]) {
                dqMax.pop_back();
            }
            dqMax.push_back(i);
            while (!dqMin.empty() && nums[dqMin.back()] > nums[i]) {
                dqMin.pop_back();
            }
            dqMin.push_back(i);

            for (; j < i && (nums[dqMax.front()] - nums[dqMin.front()] > k); ++j) {
                if (!dqMax.empty() && dqMax.front() == j) { dqMax.pop_front(); }
                if (!dqMin.empty() && dqMin.front() == j) { dqMin.pop_front(); }
            }
            dp[i] = presums[i - 1] - (j >= 2 ? presums[j - 2] : 0);
            dp[i] = (dp[i] % M + M) % M;
            presums[i] = (presums[i - 1] + dp[i]) % M;
        }

        return dp[n];
    }
};
