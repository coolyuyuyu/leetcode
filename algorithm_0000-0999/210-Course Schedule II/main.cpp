class Solution {
public:
    vector<int> bfs(int n, vector<vector<int>>& prerequisites) {
        vector<int> graph[n];
        int in[n];
        std::fill(in, in + n, 0);
        for (const auto& prerequisite : prerequisites) {
            int a = prerequisite[0], b = prerequisite[1];
            graph[b].push_back(a);
            ++in[a];
        }

        vector<int> ret;

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ret.push_back(u);

            for (int v : graph[u]) {
                if (--in[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (ret.size() != n) {
            ret.clear();
        }

        return ret;
    }

    vector<int> dfs(int n, vector<vector<int>>& prerequisites) {
        vector<int> graph[n];
        for (const auto& prerequisite : prerequisites) {
            int a = prerequisite[0], b = prerequisite[1];
            graph[b].push_back(a);
        }

        vector<int> ret;

        enum class State {
            kNone,
            kProcessing,
            kVisited,
        };
        State state[n];
        std::fill(state, state + n, State::kNone);
        std::function<bool(int)> checkCycle = [&](int cur) {
            switch (state[cur]) {
            case State::kProcessing: return true;
            case State::kVisited: return false;
            }

            state[cur] = State::kProcessing;
            for (int nxt : graph[cur]) {
                if (checkCycle(nxt)) {
                    return true;
                }
            }
            state[cur] = State::kVisited;

            ret.push_back(cur);

            return false;
        };

        for (int i = 0; i < n; ++i) {
            if (checkCycle(i)) {
                ret.clear();
                break;
            }
        }
        std::reverse(ret.begin(), ret.end());

        return ret;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //return bfs(numCourses, prerequisites);
        return dfs(numCourses, prerequisites);
    }
};
