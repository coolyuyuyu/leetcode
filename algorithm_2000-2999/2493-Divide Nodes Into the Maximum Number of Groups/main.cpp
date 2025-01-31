class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> graph[n + 1];
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        unordered_map<int, int> gid2depth;
        for (int root = 1; root <= n; ++root) {
            vector<int> depths(n + 1, 0);
            queue<int> q;

            int gid = INT_MAX;
            int depth = 0;
            depths[root] = 1;
            q.push(root);

            while (!q.empty()) {
                ++depth;
                for (int i = q.size(); 0 < i--;) {
                    int cur = q.front();
                    q.pop();

                    gid = std::min(gid, cur);

                    for (int nxt : graph[cur]) {
                        if (depths[nxt] == 0) {
                            depths[nxt] = depth + 1;
                            q.push(nxt);
                        }
                        else if (depths[nxt] == depth) {
                            return -1;
                        }
                    }
                }
            }
            gid2depth[gid] = std::max(gid2depth[gid], depth);
        }

        int ret = 0;
        for (const auto& [_, depth] : gid2depth) {
            ret += depth;
        }

        return ret;
    }
};
