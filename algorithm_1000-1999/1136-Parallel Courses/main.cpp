class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> graph(n);
        vector<int> in(n);
        for (const auto& relation : relations) {
            graph[relation[0] - 1].push_back(relation[1] - 1);
            ++in[relation[1] - 1];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        int ret = 0;
        int taken = 0;
        while (!q.empty()) {
            ++ret;

            taken += q.size();
            for (int qsize = q.size(); 0 < qsize--;) {
                int cur = q.front();
                q.pop();

                for (int nxt : graph[cur]) {
                    if (--in[nxt] == 0) {
                        q.push(nxt);
                    }
                }
            }
        }

        return taken == n ? ret : -1;
    }
};
