class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> graph[numCourses];

        int indegree[numCourses];
        std::fill(indegree, indegree + numCourses, 0);
        for (const auto& prerequisite : prerequisites) {
            int a = prerequisite[0], b = prerequisite[1];
            graph[a].push_back(b);
            ++indegree[b];
        }

        unordered_set<int> pres[numCourses];

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            pres[i].insert(i);
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int nxt : graph[cur]) {
                pres[nxt].insert(pres[cur].begin(), pres[cur].end());
                if (--indegree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        vector<bool> ret(queries.size());
        for (int i = 0; i < ret.size(); ++i) {
            int u = queries[i][0], v = queries[i][1];
            ret[i] = pres[v].find(u) != pres[v].end();
        }

        return ret;
    }
};
