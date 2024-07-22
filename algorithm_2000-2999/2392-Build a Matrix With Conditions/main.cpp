class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        std::function<vector<int>(const vector<vector<int>>&)> f = [&](const vector<vector<int>>& conditions) -> vector<int> {
            unordered_set<int> graph[k + 1];
            vector<int> ins(k + 1, 0);
            for (const auto& condition : conditions) {
                int u = condition[0], v = condition[1];
                if (graph[u].insert(v).second) {
                    ++ins[v];
                }
            }

            vector<int> ret;

            queue<int> q;
            for (int i = 1; i <= k; ++i) {
                if (ins[i] == 0) {
                    q.push(i);
                }
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();

                ret.push_back(u);
                for (int v : graph[u]) {
                    if (--ins[v] == 0) {
                        q.push(v);
                    }
                }
            }
            if (ret.size() < k) {
                ret.clear();
            }

            return ret;
        };

        vector<int> rowSeq = f(rowConditions);
        if (rowSeq.empty()) { return {}; }
        vector<int> colSeq = f(colConditions);
        if (colSeq.empty()) { return {}; }

        vector<pair<int, int>> positions(k + 1);
        for (int i = 0; i < k; ++i) {
            positions[rowSeq[i]].first = i;
            positions[colSeq[i]].second = i;
        }

        vector<vector<int>> ret(k, vector<int>(k));
        for (int i = 1; i <= k; ++i) {
            const auto& [r, c] = positions[i];
            ret[r][c] = i;
        }

        return ret;
    }
};
