class Solution {
public:
    vector<int> bfs(vector<vector<int>>& graph) {
        int n = graph.size();

        int out[n];
        std::fill(out, out + n, 0);
        vector<int> pre[n];
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                ++out[u];
                pre[v].push_back(u);
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (out[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ret;
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            ret.push_back(v);

            for (int u : pre[v]) {
                if (--out[u] == 0) {
                    q.push(u);
                }
            }
        }
        std::sort(ret.begin(), ret.end());

        return ret;
    }

    vector<int> dfs(vector<vector<int>>& graph) {
        int n = graph.size();

        enum class State : unsigned char {
            kNone,
            kProcessing,
            kProcessed,
        };
        State states[n];
        std::fill(states, states + n, State::kNone);
        std::function<bool(int)> checkCycle = [&](int cur) {
            switch (states[cur]) {
                case State::kProcessing: return true;
                case State::kProcessed: return false;
            }

            states[cur] = State::kProcessing;
            for (int nxt : graph[cur]) {
                if (checkCycle(nxt)) {
                    return true;
                }
            }
            states[cur] = State::kProcessed;

            return false;
        };

        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if (!checkCycle(i)) {
                ret.push_back(i);
            }
        }

        return ret;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        return bfs(graph);
        //return dfs(graph);
    }
};
