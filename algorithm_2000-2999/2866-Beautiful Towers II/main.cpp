class Solution {
public:
    vector<long long> maximumSumOfIncreasingHeights(vector<int> maxHeights) {
        maxHeights.insert(maxHeights.begin(), 0);
        maxHeights.push_back(0);

        int n = maxHeights.size();

        stack<int> stk;
        stk.push(maxHeights[0]);

        // dp[i]: max sum of possible heights[0:i]
        long long dp[n];
        dp[0] = maxHeights[0];

        long long sum = 0;
        for (int i = 1; i < maxHeights.size(); ++i) {
            while (!stk.empty() && maxHeights[stk.top()] > maxHeights[i]) {
                int p1 = stk.top();
                stk.pop();
                int p2 = stk.top();
                sum -= (long long)(p1 - p2) * maxHeights[p1];
            }
            sum += (long long)(i - stk.top()) * maxHeights[i];
            dp[i] = sum;

            stk.push(i);
        }

        return vector<long long>(dp + 1, dp + n - 1);
    }

    long long maximumSumOfHeights(vector<int>& maxHeights) {
        vector<long long> lft = maximumSumOfIncreasingHeights(maxHeights);

        vector<int> revMaxHeights(maxHeights);
        std::reverse(revMaxHeights.begin(), revMaxHeights.end());
        vector<long long> rht = maximumSumOfIncreasingHeights(revMaxHeights);
        std::reverse(rht.begin(), rht.end());

        long long ret = 0;
        int n = maxHeights.size();
        for (int i = 0; i < n; ++i) {
            long long sum = lft[i] + rht[i] - maxHeights[i];
            ret = std::max(ret, sum);
        }

        return ret;
    }
};
