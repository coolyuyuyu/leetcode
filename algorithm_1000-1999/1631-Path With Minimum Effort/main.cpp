class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    DisjointSets(const DisjointSets& ds)
        : m_parents(ds.m_parents) {
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

private:
    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

    mutable vector<int> m_parents;
};

class Solution {
public:
    int greedy(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights.empty() ? 0 : heights[0].size();

        vector<tuple<int, int, int>> edges;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if ((r + 1) < m) {
                    edges.emplace_back(abs(heights[r][c] - heights[r + 1][c]), r * n + c, (r + 1) * n + c);
                }
                if ((c + 1) < n) {
                    edges.emplace_back(abs(heights[r][c] - heights[r][c + 1]), r * n + c, r * n + c + 1);
                }
            }
        }
        std::sort(
            edges.begin(), edges.end(),
            [](const auto& edge1, const auto& edge2) {
                return std::get<0>(edge1) < std::get<0>(edge2);
            });

        DisjointSets ds(m * n);
        int srcId = 0, dstId = m * n - 1;
        for (const auto& [cost, id1, id2] : edges) {
            ds.merge(id1, id2);
            if (ds.connected(srcId, dstId)) {
                return cost;
            }
        }

        return 0;
    }

    int bsearch(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights.empty() ? 0 : heights[0].size();
        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};


        std::function<bool(int)> isOk = [&](int maxDiff) -> bool {
            queue<pair<int, int>> stk;
            vector<vector<bool>> visited(m, vector<bool>(n, false));

            stk.emplace(0, 0);
            visited[0][0] = true;

            while (!stk.empty()) {
                auto [r, c] = stk.front();
                stk.pop();

                for (auto [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || m <= x || y < 0 || n <= y) { continue; }
                    if (visited[x][y]) { continue; }
                    if (abs(heights[x][y] - heights[r][c]) > maxDiff) { continue; }

                    stk.emplace(x, y);
                    visited[x][y] = true;
                }
            }

            return visited[m - 1][n - 1];
        };

        int lo = 0, hi = 1e6;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (isOk(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        return greedy(heights);
        //return bsearch(heights);
    }
};
