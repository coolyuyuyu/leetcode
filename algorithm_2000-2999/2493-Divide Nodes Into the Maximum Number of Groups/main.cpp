class Solution {
public:

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbors(n + 1);
        for (const auto& e : edges) {
            neighbors[e[0]].push_back(e[1]);
            neighbors[e[1]].push_back(e[0]);
        }

        unordered_map<int, int> maxGroupCnts; // <connected component id, max number of group>
        for (int root = 1; root <= n; ++root) {

            // bfs
            queue<int> q; // node, depth
            q.emplace(root);

            vector<int> depths(n + 1);
            depths[root] = 1;

            int ccId = root; // id of connected component
            int depth = 0;
            while (!q.empty()) {
                depth += 1;
                for (size_t n = q.size(); 0 < n--;) {
                    int node = q.front();
                    q.pop();

                    ccId = std::min(ccId, node);

                    for (int neighbor: neighbors[node]) {
                        if (depths[neighbor] == 0) {
                            depths[neighbor] = depth + 1;
                            q.emplace(neighbor);
                        }
                        else if (depths[neighbor] == depth) {
                            return -1;
                        }
                    }
                }
            }

            maxGroupCnts[ccId] = std::max(maxGroupCnts[ccId], depth);
        }

        int ret = 0;
        for (const auto& p : maxGroupCnts) {
            ret += p.second;
        }

        return ret;
    }
};
