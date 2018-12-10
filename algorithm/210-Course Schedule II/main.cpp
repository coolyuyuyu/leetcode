class Solution {
public:
    enum State {NONE, TEMPORARY, VISITED};

    bool findOrderDfsHelper(int i, const vector<vector<int>>& adjLists, vector<State>& states, vector<int>& ans) {
        switch (states[i]) {
        case VISITED:
            return true;
        case TEMPORARY:
            return false;
        }

        states[i] = TEMPORARY;
        for (int j : adjLists[i]) {
            if (!findOrderDfsHelper(j, adjLists, states, ans)) {
                return false;
            }
        }
        states[i] = VISITED;

        ans.push_back(i);
        return true;
    }

    // Dfs algorithm
    vector<int> findOrderDfs(int numCourses, const vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adjLists(numCourses);
        for (const pair<int, int>& prerequisite : prerequisites) {
            adjLists[prerequisite.second].push_back(prerequisite.first);
        }

        vector<int> ans;
        vector<State> states(numCourses, NONE);
        for (size_t i = 0; i < numCourses; ++i) {
            if (states[i] == NONE) {
                if (!findOrderDfsHelper(i, adjLists, states, ans)) {
                    ans.clear();
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }

    // Kahn algorithm
    vector<int> findOrderKahn(int numCourses, const vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adjLists(numCourses);
        vector<size_t> inDegrees(numCourses, 0);
        for (const pair<int, int>& prerequisite : prerequisites) {
            adjLists[prerequisite.second].push_back(prerequisite.first);
            ++inDegrees[prerequisite.first];
        }

        vector<int> ans;
        queue<int> nodes;
        for (int u = 0; u < numCourses; ++u) {
            if (inDegrees[u] == 0) {
                nodes.push(u);
            }
        }
        while (!nodes.empty()) {
            int u = nodes.front();
            nodes.pop();

            ans.push_back(u);

            for (int v : adjLists[u]) {
                if (--inDegrees[v] == 0) {
                    nodes.push(v);
                }
            }
        }

        if(any_of(inDegrees.begin(), inDegrees.end(), [](int d){return d != 0;})) {
            ans.clear();
        }

        return ans;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        //return findOrderDfs(numCourses, prerequisites);

        return findOrderKahn(numCourses, prerequisites);
    }
};