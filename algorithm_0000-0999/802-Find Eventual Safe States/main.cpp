class Solution {
public:
    vector<int> bfs(vector<vector<int>>& graph) {
        int n = graph.size();

        int out[n];
        std::fill(out, out + n, 0);
        vector<int> pres[n];
        for (int from = 0; from < n; ++from) {
            for (int to : graph[from]) {
                ++out[from];
                pres[to].push_back(from);
            }
        }

        vector<int> ret;

        queue<int> q;
        for (int v = 0; v < n; ++v) {
            if (out[v] == 0) {
                q.push(v);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            ret.push_back(cur);

            for (int pre : pres[cur]) {
                if (--out[pre] == 0) {
                    q.push(pre);
                }
            }
        }
        std::sort(ret.begin(), ret.end());

        return ret;
    }

    vector<int> dfs(vector<vector<int>>& graph) {
        int n = graph.size();

        enum class State {
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
        for (int v = 0; v < n; ++v) {
            if (!checkCycle(v)) {
                ret.push_back(v);
            }
        }

        return ret;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        return bfs(graph);
        //return dfs(graph);
    }
};
