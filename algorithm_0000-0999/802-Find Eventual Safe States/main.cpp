class Solution {
public:
    vector<int> bfs(const vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> oDegrees(n, 0);
        vector<vector<int>> pres(n);
        for (int from = 0; from < n; ++from) {
            for (int to : graph[from]) {
                pres[to].push_back(from);
                ++oDegrees[from];
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (oDegrees[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ret;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            ret.push_back(cur);

            for (int pre : pres[cur]) {
                if (--oDegrees[pre] == 0) {
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
            kVisited,
        };
        vector<State> states(n, State::kNone);

        std::function<bool(int)> checkCycle = [&](int cur) {
            if (states[cur] == State::kProcessing) {
                return true;
            }
            else if (states[cur] == State::kVisited) {
                return false;
            }

            states[cur] = State::kProcessing;
            for (int nxt : graph[cur]) {
                if (checkCycle(nxt)) {
                    return true;
                }
            }
            states[cur] = State::kVisited;

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
        //return bfs(graph);
        return dfs(graph);
    }
};
