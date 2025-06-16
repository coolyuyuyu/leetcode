class Solution {
public:
    int M = 1e9 + 7;
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        // dp[i]: the total number of ways to partition nums[1:i].
        int dp[n + 1];
        dp[0] = 1;

        // X X X X X X X
        //         j   i
        // j: the smallest index to form nums[i:j] a valid partition
        // dp[i] = dp[j - 1] + ... dp[i - 1]

        // prefix[i]: sum of dp[1], dp[2], ... dp[i]
        // => dp[i] = prefix[i - 1] - prefix[j - 2];

        int prefix[n + 1];
        prefix[0] = dp[0];

        deque<int> dqMax, dqMin;

        for (int j = 1, i = 1; i <= n; ++i) {
            while (!dqMax.empty() && nums[dqMax.back()] < nums[i]) {
                dqMax.pop_back();
            }
            dqMax.push_back(i);
            while (!dqMin.empty() && nums[dqMin.back()] > nums[i]) {
                dqMin.pop_back();
            }
            dqMin.push_back(i);

            for (; j <= i && nums[dqMax.front()] - nums[dqMin.front()] > k; ++j) {
                if (!dqMin.empty() && dqMin.front() == j) { dqMin.pop_front(); }
                if (!dqMax.empty() && dqMax.front() == j) { dqMax.pop_front(); }
            }

            dp[i] = ((prefix[i - 1] - (j >= 2 ? prefix[j - 2] : 0)) % M + M) % M;
            prefix[i] = (prefix[i - 1] + dp[i]) % M;
        }

        return dp[n];
    }
};
