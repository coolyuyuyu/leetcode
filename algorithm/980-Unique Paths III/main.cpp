class Solution {
public:
    class DisjointSets {
    public:
        DisjointSets(size_t rowCnt, size_t colCnt)
            : m_rowCnt(rowCnt)
            , m_colCnt(colCnt)
            , m_size(0)
            , m_parents(rowCnt * colCnt, INDEX_INVALID) {
        }

        inline bool isEnabled(size_t row, size_t col) const {
            return m_parents[encode(row, col)] != INDEX_INVALID;
        }

        inline void enable(size_t row, size_t col) {
            assert(!isEnabled(row, col));

            size_t index = encode(row, col);
            m_parents[index] = index;
            ++m_size;
        }

        inline size_t find(size_t row, size_t col) const {
            assert(isEnabled(row, col));

            return find(encode(row, col));
        }

        inline void merge(size_t row1, size_t col1, size_t row2, size_t col2) {
            assert(isEnabled(row1, col1) && isEnabled(row2, col2));

            merge(encode(row1, col1), encode(row2, col2));
        }

        inline size_t size() const {
            return m_size;
        }

    private:
        inline size_t encode(size_t row, size_t col) const {
            return row * m_colCnt + col;
        }

        size_t find(size_t index) const {
            if (m_parents[index] != index) {
                const_cast<DisjointSets*>(this)->m_parents[index] = find(m_parents[index]);
            }
            return m_parents[index];
        }

        void merge(size_t index1, size_t index2) {
            size_t root1 = find(index1);
            size_t root2 = find(index2);
            if (root1 != root2) {
                m_parents[root1] = root2;
                --m_size;
            }
        }

        static const size_t INDEX_INVALID;

        size_t m_rowCnt;
        size_t m_colCnt;
        size_t m_size;
        vector<size_t> m_parents;
    };

    void dfs(vector<vector<int>>& grid, size_t row, size_t col, size_t len, size_t& count) {
        switch (grid[row][col]) {
            case 2:
                if (len == 0) {
                    ++count;
                }
                return;
            case 0:
                size_t rowCnt = grid.size(), colCnt = grid.empty() ? 0 : grid.front().size();
                grid[row][col] = -1;

                // lft
                if (0 < col) {
                    dfs(grid, row, col - 1, len - 1, count);
                }

                // upr
                if (0 < row) {
                    dfs(grid, row - 1, col, len - 1, count);
                }

                // rht
                if (col + 1 < colCnt) {
                    dfs(grid, row, col + 1, len - 1, count);
                }

                // btm
                if (row + 1 < rowCnt) {
                    dfs(grid, row + 1, col, len - 1, count);
                }

                grid[row][col] = 0;
                break;
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        size_t rowCnt = grid.size(), colCnt = grid.empty() ? 0 : grid.front().size();

        pair<size_t, size_t> source;
        size_t len = 0;
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 0; col < colCnt; ++col) {
                switch (grid[row][col]) {
                    case 0:
                        ++len;
                        break;
                    case 1:
                        source = {row, col};
                        break;
                }
            }
        }

        grid[source.first][source.second] = 0;

        DisjointSets ds(rowCnt, colCnt);
        if (0 < rowCnt && 0 < colCnt && grid[0][0] == 0) {
            ds.enable(0, 0);
        }
        for (size_t col = 1; col < colCnt; ++col) {
            if (grid[0][col] == 0) {
                ds.enable(0, col);
                if (grid[0][col - 1] == 0) {
                    ds.merge(0, col, 0, col - 1);
                }
            }
        }
        for (size_t row = 1; row < rowCnt; ++row) {
            if (grid[row][0] == 0) {
                ds.enable(row, 0);
                if (grid[row - 1][0] == 0) {
                    ds.merge(row, 0, row - 1, 0);
                }
            }
        }
        for (size_t row = 1; row < rowCnt; ++row) {
            for (size_t col = 1; col < colCnt; ++col) {
                if (grid[row][col] == 0) {
                    ds.enable(row, col);
                    if (grid[row - 1][col] == 0) {
                        ds.merge(row, col, row - 1, col);
                    }
                    if (grid[row][col - 1] == 0) {
                        ds.merge(row, col, row, col - 1);
                    }
                }
            }
        }
        if (ds.size() != 1) {
            return 0;
        }

        size_t count = 0;
        dfs(grid, source.first, source.second, len + 1, count);

        grid[source.first][source.second] = 1;

        return count;
    }
};

const size_t Solution::DisjointSets::INDEX_INVALID = numeric_limits<size_t>::max();