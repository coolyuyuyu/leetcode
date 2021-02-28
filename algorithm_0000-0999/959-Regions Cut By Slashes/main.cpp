class Solution {
public:
    class DisjointSets {
    public:
        DisjointSets(size_t count)
            : m_parents(count)
            , m_count(count) {
            for (size_t i = 0; i < m_parents.size(); ++i) {
                m_parents[i] = i;
            }
        }

        size_t find(size_t i) {
            if (m_parents[i] != i) {
                m_parents[i] = find(m_parents[i]);
            }

            return m_parents[i];
        }

        void merge(size_t i, size_t j) {
            size_t rootI = find(i);
            size_t rootJ = find(j);
            if (rootI != rootJ) {
                --m_count;
            }

            m_parents[rootI] = rootJ;
        }

        inline size_t size() const {
            return m_count;
        }

    private:
        vector<size_t> m_parents;
        size_t m_count;
    };

    size_t regionsBySlashes(vector<string>& grid) {
        size_t rowCnt = grid.size(), colCnt = grid.empty() ? 0 : grid.front().size();
        DisjointSets ds(rowCnt * colCnt * 4);
        for (size_t col = 0; col < colCnt; ++col) {
            size_t base = col * 4;
            if (0 < col) {
                ds.merge(base + 1, (col - 1) * 4 + 2);
            }
            switch (grid[0][col]) {
                case '/':
                    ds.merge(base + 0, base + 1);
                    ds.merge(base + 2, base + 3);
                    break;
                case '\\':
                    ds.merge(base + 0, base + 2);
                    ds.merge(base + 1, base + 3);
                    break;
                default:
                    ds.merge(base + 0, base + 1);
                    ds.merge(base + 1, base + 2);
                    ds.merge(base + 2, base + 3);
                    break;
            }
        }
        for (size_t row = 0; row < rowCnt; ++row) {
            size_t base = row * colCnt * 4;
            if (0 < row) {
                ds.merge(base + 0, (row - 1) * colCnt * 4 + 3);
            }
            switch (grid[row][0]) {
                case '/':
                    ds.merge(base + 0, base + 1);
                    ds.merge(base + 2, base + 3);
                    break;
                case '\\':
                    ds.merge(base+ 0, base + 2);
                    ds.merge(base+ 1, base + 3);
                    break;
                default:
                    ds.merge(base + 0, base + 1);
                    ds.merge(base + 1, base + 2);
                    ds.merge(base + 2, base + 3);
                    break;
            }
        }

        for (size_t row = 1; row < rowCnt; ++row) {
            for (size_t col = 1; col < colCnt; ++col) {
                size_t base = (row * colCnt  + col) * 4;
                ds.merge(base + 0, ((row - 1) * colCnt  + col) * 4 + 3);
                ds.merge(base + 1, (row * colCnt  + (col - 1)) * 4 + 2);
                switch (grid[row][col]) {
                    case '/':
                        ds.merge(base + 0, base + 1);
                        ds.merge(base + 2, base + 3);
                        break;
                    case '\\':
                        ds.merge(base + 0, base + 2);
                        ds.merge(base + 1, base + 3);
                        break;
                    default:
                        ds.merge(base * 4 + 0, base + 1);
                        ds.merge(base * 4 + 1, base + 2);
                        ds.merge(base * 4 + 2, base + 3);
                        break;
                }
            }
        }

        return ds.size();
    }
};