class Solution {
public:
    bool bfs(int n, const vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        vector<int> iDegrees(n, 0);
        for (const auto& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            ++iDegrees[prerequisite[0]];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (iDegrees[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int from = q.front();
            q.pop();

            --n;

            for (int to : graph[from]) {
                if (--iDegrees[to] == 0) {
                    q.push(to);
                }
            }
        }

        return (n == 0);
    }

    bool dfs(int n, const vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        for (const auto& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }

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

        for (int i = 0; i < n; ++i) {
            if (checkCycle(i)) {
                return false;
            }
        }

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //return bfs(numCourses, prerequisites);
        return dfs(numCourses, prerequisites);
    }
};
