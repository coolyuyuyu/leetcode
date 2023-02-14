class Solution {
public:
    // Kahn's algorithm
    // Time: O(V + E)
    bool bfs(int numCourses, const vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses);
        vector<vector<int>> nexts(numCourses);
        for (const auto& prerequisite : prerequisites) {
            nexts[prerequisite[0]].push_back(prerequisite[1]);
            ++inDegrees[prerequisite[1]];
        }

        queue<int> q;
        for (int course = 0; course < numCourses; ++course) {
            if (inDegrees[course] == 0) {
                q.push(course);
            }
        }
        while (!q.empty()) {
            int course = q.front();
            q.pop();

            --numCourses;

            for (int next : nexts[course]) {
                if (--inDegrees[next] == 0) {
                    q.push(next);
                }
            }
        }

        return numCourses == 0;
    }

    // ---

    enum class State {
        kNone,
        kProcessed,
        kVisited,
    };

    bool checkCycle(const vector<vector<int>>& nexts, int node, vector<State>& states) {
        if (states[node] == State::kVisited) {
            return false;
        }
        if (states[node] == State::kProcessed) {
            return true;
        }

        states[node] = State::kProcessed;
        for (int next : nexts[node]) {
            if (checkCycle(nexts, next, states)) {
                return true;
            }
        }
        states[node] = State::kVisited;

        return false;
    }

    // cycle detection
    // Time: O(V + E)
    bool dfs(int numCourses, const vector<vector<int>>& prerequisites) {
        vector<vector<int>> nexts(numCourses);
        for (const auto& prerequisite : prerequisites) {
            nexts[prerequisite[0]].push_back(prerequisite[1]);
        }

        vector<State> states(numCourses, State::kNone);
        for (int i = 0; i < numCourses; ++i) {
            if (checkCycle(nexts, i, states)) {
                return false;
            }
        }

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return bfs(numCourses, prerequisites);
        //return dfs(numCourses, prerequisites);
    }
};

// prerequisite [a, b]
//     => b -> a
//     => a has one in-degree from b
