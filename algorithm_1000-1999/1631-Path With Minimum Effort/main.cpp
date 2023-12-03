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
    int bsearch(vector<vector<int>>& heights) {
        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        int m = heights.size(), n = heights.empty() ? 0 : heights[0].size();
        if (m == 1 && n == 1) { return 0; }

        std::function<bool(int)> canReach = [&](int maxDiff) {
            bool visited[m][n];
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    visited[r][c] = false;
                }
            }
            queue<pair<int, int>> q;

            visited[0][0] = true;
            q.emplace(0, 0);

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                    if (visited[x][y]) { continue; }
                    if (abs(heights[r][c] - heights[x][y]) > maxDiff) { continue; }

                    if (x == m - 1 && y == n - 1) { return true; }

                    q.emplace(x, y);
                    visited[x][y] = true;
                }
            }

            return false;
        };

        int lo = 0, hi = 1e6 - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canReach(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    int greedy(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights.empty() ? 0 : heights[0].size();
        if (m == 1 && n == 1) { return 0; }

        std::function<int(int, int)> getId = [&](int r, int c) {
            return r * n + c;
        };

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<>> pq;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int id = getId(r, c);
                if (r + 1 < m) {
                    pq.emplace(abs(heights[r][c] - heights[r + 1][c]), id, getId(r + 1, c));
                }
                if (c + 1 < n) {
                    pq.emplace(abs(heights[r][c] - heights[r][c + 1]), id, getId(r, c + 1));
                }
            }
        }

        int src = getId(0, 0), dst = getId(m - 1, n - 1);
        DisjointSets ds(m * n);
        while (!pq.empty()) {
            auto [diff, id1, id2] = pq.top();
            pq.pop();

            ds.merge(id1, id2);
            if (ds.connected(src, dst)) {
                return diff;
            }
        }

        return 0;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        //return bsearch(heights);
        return greedy(heights);
    }
};