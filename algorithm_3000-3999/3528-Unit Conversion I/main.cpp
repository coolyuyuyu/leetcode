class Solution {
public:
    int M = 1e9 + 7;

    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1;

        vector<pair<int, int>> graph[n];
        for (const auto& conversion : conversions) {
            int s = conversion[0], d = conversion[1], f = conversion[2];
            graph[s].emplace_back(d, f);
        }

        vector<int> ret(n);
        ret[0] = 1;
        for (queue<int> q({0}); !q.empty();) {
            int s = q.front();
            q.pop();

            for (const auto& [d, f] : graph[s]) {
                ret[d] = 1LL * ret[s] * f % M;
                q.push(d);
            }
        }

        return ret;
    }
};
