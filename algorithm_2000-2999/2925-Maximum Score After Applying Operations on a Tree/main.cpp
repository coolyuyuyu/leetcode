class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        int root = 0;

        vector<int> next[n];
        for (const auto& edge : edges) {
            next[edge[0]].push_back(edge[1]);
            next[edge[1]].push_back(edge[0]);
        }

        long long sum[n];
        std::copy(values.begin(), values.end(), sum);
        std::function<long long(int, int)> dfs1 = [&](int cur, int pre) {
            long long& ret = sum[cur];
            for (int nxt : next[cur]) {
                if (nxt == pre) { continue; }
                ret += dfs1(nxt, cur);
            }

            return ret;
        };
        dfs1(root, -1);

        std::function<long long(int, int)> dfs2 = [&](int cur, int pre) -> long long{
            if (next[cur].size() == 1 && cur != 0) { return 0; }

            long long sum1 = sum[cur] - values[cur];
            long long sum2 = values[cur];
            for (int nxt : next[cur]) {
                if (nxt == pre) { continue; }
                sum2 += dfs2(nxt, cur);
            }

            return std::max<long long>(sum1, sum2);
        };
        return dfs2(root, -1);
    }
};
