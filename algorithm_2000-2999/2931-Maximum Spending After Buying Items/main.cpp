class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int m = values.size(), n = values.empty() ? 0 : values[0].size();

        auto comp = [&](const pair<int, int>& rc1, const pair<int, int>& rc2) {
            auto [r1, c1] = rc1;
            auto [r2, c2] = rc2;
            return values[r1][c1] > values[r2][c2];
        };
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        for (int r = 0; r < m; ++r) {
            pq.emplace(r, n - 1);
        }

        long long ret = 0;
        for (int i = 1; i <= m * n; ++i) {
            auto [r, c] = pq.top();
            pq.pop();

            ret += 1LL * i * values[r][c];

            if (c > 0) {
                pq.emplace(r, c - 1);
            }
        }

        return ret;
    }
};
