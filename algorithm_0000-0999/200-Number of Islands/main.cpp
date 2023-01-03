class DisjointSets {
public:
    DisjointSets(int rowCnt, int colCnt)
        : m_rowCnt(rowCnt)
        , m_colCnt(colCnt)
        , m_roots(rowCnt * colCnt, kInvalidId)
        , m_size(0) {
    }

    size_t size() const {
        return m_size;
    }

    void connect(int r1, int c1, int r2, int c2) {
        size_t elem1 = encode(r1, c1), elem2 = encode(r2, c2);
        if (m_roots[elem1] == kInvalidId) {
            m_roots[elem1] = elem1;
            ++m_size;
        }
        if (m_roots[elem2] == kInvalidId) {
            m_roots[elem2] = elem2;
            ++m_size;
        }

        size_t root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_roots[root1] = root2;
            --m_size;
        }
    }

private:
    size_t root(size_t elem) const {
        if (m_roots[elem] != elem) {
            m_roots[elem] = root(m_roots[elem]);
        }

        return m_roots[elem];
    }

    size_t encode(size_t r, size_t c) {
        return r * m_colCnt + c;
    }

    size_t m_rowCnt;
    size_t m_colCnt;

    static size_t kInvalidId;
    mutable vector<size_t> m_roots;
    size_t m_size;
};

size_t DisjointSets::kInvalidId = std::numeric_limits<size_t>::max();

class Solution {
public:
    int union_find(const vector<vector<char>>& grid) {
        static vector<vector<int>> dirs = {{0, 1}, {1, 0}};

        int m = grid.size(), n = grid[0].size();
        DisjointSets ds(m, n);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '0') {
                    continue;
                }
                ds.connect(r, c, r, c);

                static vector<vector<int>> dirs = {{0, 1}, {1, 0}};
                for (const auto& dir : dirs) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if (0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] == '1') {
                        ds.connect(r, c, nr, nc);
                    }
                }
            }
        }

        return ds.size();
    }

    int bfs(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int ret = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '0') {
                    continue;
                }

                grid[r][c] = '0';

                queue<array<int, 2>> q;
                q.push({r, c});

                while (!q.empty()) {
                    int x = q.front()[0], y = q.front()[1];
                    q.pop();

                    static vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
                    for (const auto& dir : dirs) {
                        int nx = x + dir[0], ny = y + dir[1];
                        if (0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] == '1') {
                            grid[nx][ny] = '0';
                            q.push({nx, ny});
                        }
                    }
                }

                ++ret;
            }
        }

        return ret;
    }

    int numIslands(vector<vector<char>>& grid) {
        //return union_find(grid);
        return bfs(grid);
    }
};
