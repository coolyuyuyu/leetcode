class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, queue<int>> graph;
        unordered_map<int, int> in, out;
        for (const auto& p : pairs) {
            int from = p[0], to = p[1];
            graph[from].push(to);
            ++in[to], ++out[from];
        }

        int src = -1;
        for (const auto& [node, _]: graph) {
            if (out[node] - in[node] == 1) {
                src = node;
            }
        }
        if (src == -1) {
            src = pairs[0][0];
        }

        vector<int> path;
        for (stack<int> stk({src}); !stk.empty();) {
            if (graph[stk.top()].empty()) {
                path.push_back(stk.top());
                stk.pop();
            }
            else {
                int nxt = graph[stk.top()].front();
                graph[stk.top()].pop();
                stk.push(nxt);
            }
        }

        vector<vector<int>> ret;
        for (int i = path.size(); 1 < i--;) {
            ret.push_back({path[i], path[i - 1]});
        }

        return ret;
    }
};
