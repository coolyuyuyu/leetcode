class Solution {
public:
    // TLE
    int dp_TopDown(vector<int>& cost, size_t n) {
        if (n == 0 || n == 1) {
            return 0;
        }
        return std::min(dp_TopDown(cost, n - 2) + cost[n - 2], dp_TopDown(cost, n - 1) + cost[n - 1]);
    }

    int dp_TopDownMemorization(vector<int>& ans, vector<int>& cost, size_t n) {
        if (n <= 1) {
            return 0;
        }
        else if (ans[n] != -1) {
            return ans[n];
        }

        int c1 = dp_TopDownMemorization(ans, cost, n - 2) + cost[n - 2];
        int c2 = dp_TopDownMemorization(ans, cost, n - 1) + cost[n - 1];
        ans[n] = std::min(c1, c2);

        return ans[n];
    }

    // Space: O(N)
    int dp_BtmUp(vector<int>& cost) {
        vector<int> ans(cost.size() + 1);
        for (size_t i = 2; i < ans.size(); ++i) {
            ans[i] = std::min(ans[i - 2] + cost[i - 2], ans[i - 1] + cost[i - 1]);
        }

        return ans.back();
    }

    // Space: O(1)
    int dp_BtmUpConstSpace(vector<int>& cost) {
        int x = 0, y = 0;
        for (size_t i = 2; i <= cost.size(); ++i) {
            int tmp = std::min(x + cost[i - 2], y + cost[i - 1]);
            x = y;
            y = tmp;
        }

        return y;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        //return dp_TopDown(cost, cost.size());

        //vector<int> ans(cost.size() + 1, -1);
        //return dp_TopDownMemorization(ans, cost, cost.size());

        //return dp_BtmUp(cost);

        return dp_BtmUpConstSpace(cost);
    }
};
