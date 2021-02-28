class Solution {
public:
    void fillWater(int row, int col, vector<vector<char>>& grid) {
        if (grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';

        //ltf
        if (0 < col) {
            fillWater(row, col - 1, grid);
        }

        //top
        if (0 < row) {
            fillWater(row - 1, col, grid);
        }

        //rht
        if (col + 1 < grid.front().size()) {
            fillWater(row, col + 1, grid);
        }

        //btm
        if (row + 1 < grid.size()) {
            fillWater(row + 1, col, grid);
        }

    }

    int numIslandsRecv(vector<vector<char>>& grid) {
        int ans = 0;

        size_t rowCnt = grid.size();
        size_t colCnt = grid.empty() ? 0 : grid.front().size();
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                if (grid[row][col] == '1') {
                    ++ans;
                    fillWater(row, col, grid);
                }
            }
        }

        return ans;
    }

    class DisjointSet {
    public:
        DisjointSet(int size)
            : m_parents(size)
            , m_size(0) {
            for (size_t i = 0; i < m_parents.size(); ++i) {
                m_parents[i] = -1;
            }
        }

        bool isEnabled(int i) {
            return 0 <= m_parents[i];
        }

        void enable(int i) {
            assert(!isEnabled(i));
            m_parents[i] = i;
            ++m_size;
        }

        int size() const {
            return m_size;
        }

        int find(int i) {
            assert(isEnabled(i));

            if (m_parents[i] != i) {
                m_parents[i] = find(m_parents[i]);
            }

            return m_parents[i];
        }

        void merge(int i, int j) {
            assert(isEnabled(i) && isEnabled(j));

            int rootI = find(i);
            int rootJ = find(j);
            if (rootI != rootJ) {
                m_parents[rootI] = rootJ;
                --m_size;
            }
        }

    private:
        vector<int> m_parents;
        int m_size;
    };

    inline int encode(int r, int c, int rowCount, int colCount) {
        return r * colCount + c;
    }

    int numIslandsDisjoingSet(vector<vector<char>>& grid) {
        int ans = 0;

        size_t rowCnt = grid.size();
        size_t colCnt = grid.empty() ? 0 : grid.front().size();
        DisjointSet ds(rowCnt * colCnt);

        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                if (grid[row][col] == '0') {
                    continue;
                }

                int key = encode(row, col, rowCnt, colCnt);
                ds.enable(key);

                // left
                if (0 < col) {
                    int keyLft = encode(row, col - 1, rowCnt, colCnt);
                    if (ds.isEnabled(keyLft)) {
                        ds.merge(key, keyLft);
                    }
                }

                // upper
                if (0 < row) {
                    int keyUpr = encode(row - 1, col, rowCnt, colCnt);
                    if (ds.isEnabled(keyUpr)) {
                        ds.merge(key, keyUpr);
                    }
                }
            }
        }

        return ds.size();
    }

    int numIslands(vector<vector<char>>& grid) {
        //return numIslandsRecv(grid);

        return numIslandsDisjoingSet(grid);
    }
};