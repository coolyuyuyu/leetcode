class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int sum = std::accumulate(possible.begin(), possible.end(), 0);
        for (int i = 0, n = possible.size(), presum = 0; i + 1< n; ++i) {
            presum += possible[i];
            int scoreLft = presum * 1 + (i + 1 - presum) * -1;
            int scoreRht = (sum - presum) * 1 + (n - sum - (i + 1 - presum)) * -1;
            if (scoreLft > scoreRht) {
                return i + 1;
            }
        }

        return -1;
    }
};
