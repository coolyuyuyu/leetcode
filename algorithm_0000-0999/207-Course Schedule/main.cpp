class Solution {
public:
    enum State {NONE, TEMPORARY, VISITED};

    bool canFinishDfsHelper(int i, const vector<vector<int>>& adjLists, vector<State>& states) {
        switch (states[i]) {
        case VISITED:
            return true;
        case TEMPORARY:
            return false;
        }

        states[i] = TEMPORARY;
        for (int j : adjLists[i]) {
            if (!canFinishDfsHelper(j, adjLists, states)) {
                return false;
            }
        }
        states[i] = VISITED;

        return true;
    }

    // Dfs algorithm
    bool canFinishDfs(int numCourses, const vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adjLists(numCourses);
        for (const pair<int, int>& prerequisite : prerequisites) {
            adjLists[prerequisite.second].push_back(prerequisite.first);
        }

        vector<State> states(numCourses, NONE);
        for (size_t i = 0; i < numCourses; ++i) {
            if (states[i] == NONE) {
                if (!canFinishDfsHelper(i, adjLists, states)) {
                    return false;
                }
            }
        }

        return true;
    }

    // Kahn algorithm
    bool canFinishKahn(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adjLists(numCourses);
        vector<size_t> inDegrees(numCourses, 0);
        for (const pair<int, int>& prerequisite : prerequisites) {
            adjLists[prerequisite.second].push_back(prerequisite.first);
            ++inDegrees[prerequisite.first];
        }

        queue<int> nodes;
        for (int u = 0; u < numCourses; ++u) {
            if (inDegrees[u] == 0) {
                nodes.push(u);
            }
        }
        while (!nodes.empty()) {
            int u = nodes.front();
            nodes.pop();

            for (int v : adjLists[u]) {
                if (--inDegrees[v] == 0) {
                    nodes.push(v);
                }
            }
        }

        return all_of(inDegrees.begin(), inDegrees.end(), [](int d){return d == 0;});
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        //return canFinishDfs(numCourses, prerequisites);

        return canFinishKahn(numCourses, prerequisites);
    }
};