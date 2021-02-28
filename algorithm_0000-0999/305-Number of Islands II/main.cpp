class Solution {
public:
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

    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> ans;

        DisjointSet ds(m * n);
        for (const pair<int, int>& pos : positions) {
            int r = pos.first, c = pos.second;
            int keyCenter = encode(r, c, m, n);
            ds.enable(keyCenter);

            // left
            if (0 < c) {
                int keyLft = encode(r, c - 1, m, n);
                if (ds.isEnabled(keyLft)) {
                    ds.merge(keyCenter, keyLft);
                }
            }

            // upper
            if (0 < r) {
                int keyUpr = encode(r - 1, c, m, n);
                if (ds.isEnabled(keyUpr)) {
                    ds.merge(keyCenter, keyUpr);
                }
            }

            // right
            if (c + 1 < n) {
                int keyRht = encode(r, c + 1, m, n);
                if (ds.isEnabled(keyRht)) {
                    ds.merge(keyCenter, keyRht);
                }
            }

            // lower
            if (r + 1 < m) {
                int keyLwr = encode(r + 1, c, m, n);
                if (ds.isEnabled(keyLwr)) {
                    ds.merge(keyCenter, keyLwr);
                }
            }

            ans.push_back(ds.size());
        }

        return ans;
    }
};