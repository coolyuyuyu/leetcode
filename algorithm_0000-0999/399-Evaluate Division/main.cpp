class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (size_t i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]].emplace_back(equations[i][1], values[i]);
            graph[equations[i][1]].emplace_back(equations[i][0], 1.0 / values[i]);
        }

        std::function<double(const string&, const string&)> dfs = [&](const string& src, const string& dst) {
            stack<pair<string, double>> stk({{src, 1.0}});
            unordered_set<string> visited;
            for (; !stk.empty();) {
                auto [cur, val] = stk.top();
                stk.pop();

                if (visited.find(cur) != visited.end()) {
                    continue;
                }
                visited.insert(cur);

                if (cur == dst) {
                    return val;
                }

                for (const auto& [next, cost] : graph[cur]) {
                    stk.emplace(next, val * cost);
                }
            }

            return -1.0;
        };

        vector<double> ret(queries.size());
        for (size_t i = 0; i < queries.size(); ++i) {
            if (graph.find(queries[i][0]) == graph.end() || graph.find(queries[i][1]) == graph.end()) {
                ret[i] = -1.0;
                continue;
            }
            ret[i] = dfs(queries[i][0], queries[i][1]);
        }

        return ret;
    }
};

