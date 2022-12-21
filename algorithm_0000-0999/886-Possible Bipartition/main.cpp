class Solution {
public:
    bool dfs_color(int n, const vector<vector<int>>& dislikes) {
        vector<vector<int>> neighbors(n);
        for (const auto& edge : dislikes) {
            neighbors[edge[0] - 1].push_back(edge[1] - 1);
            neighbors[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> colors(n, -1); // -1: no color
        auto isColored = [&colors](int node) -> bool {
            return 0 <= colors[node];
        };
        auto checkSameColor = [&colors](int node1, int node2) -> bool {
            return colors[node1] == colors[node2];
        };
        auto colorNeighbor = [&colors](int node, int neighbor) {
            if (colors[node] == 1) {
                colors[neighbor] = 2;
            }
            else {
                colors[neighbor] = 1;
            }
        };

        stack<int> stk;
        for (int src = 0; src < n; ++src) {
            if (isColored(src)) {
                continue;
            }

            stk.push(src);
            while (!stk.empty()) {
                int node = stk.top();
                stk.pop();

                for (int neighbor : neighbors[node]) {
                    if (isColored(neighbor)) {
                        if (checkSameColor(neighbor, node)) {
                            return false;
                        }
                        else {
                            continue;
                        }
                    }

                    colorNeighbor(node, neighbor);
                    stk.push(neighbor);
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        return dfs_color(n, dislikes);
    }
};
