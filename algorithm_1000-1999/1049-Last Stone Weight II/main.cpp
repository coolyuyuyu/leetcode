class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = std::accumulate(stones.begin(), stones.end(), 0);

        stones.insert(stones.begin(), 0);

        bool dp[n + 1][sum + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                dp[i][j] = false;
            }
        }
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }

        int s2 = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= (sum / 2); ++j) {
                if (dp[i - 1][j] || stones[i] <= j && dp[i - 1][j - stones[i]]) {
                    dp[i][j] = true;
                    s2 = std::max(s2, j);
                }
            }
        }

        return sum - 2 * s2;
    }
};

// The question equals to partition stones into 2 subset A and B and the difference of sum is minimized
// 1. sum = sum1 + sum2
// 2. diff = sum1 - sum2

// diff = S - 2 * S2
// => minimize diff => maximaize S2
// => S2 ranges [0, S/2]
