class Solution {
public:
    class DisjointSet {
    public:
        DisjointSet(int n)
            : m_len(n)
            , m_parents(m_len * m_len) {
            for (int i = 0; i < m_len * m_len; ++i) {
                m_parents[i] = i;
            }
        }

        inline int findByPos(int r, int c) {
            return find(getIndex(r, c));
        }

        inline void mergeByPos(int r1, int c1, int r2, int c2) {
            merge(getIndex(r1, c1), getIndex(r2, c2));
        }

    private:
        inline int getIndex(int r, int c) {
            return r * m_len + c;
        }

        int find(int i) {
            if (m_parents[i] != i) {
                m_parents[i] = find(m_parents[i]);
            }

            return m_parents[i];
        }

        void merge(int i, int j) {
            int rootI = find(i);
            int rootJ = find(j);
            if (rootI != rootJ) {
                m_parents[rootI] = rootJ;
            }
        }

        int m_len;
        vector<int> m_parents;
    };

    class Elem {
    public:
        Elem() {
        }

        Elem(int t, int r, int c)
            : time(t)
            , row(r)
            , col(c) {
        }

        bool operator<(const Elem& elem) {
            return time < elem.time;
        }

        int time;
        int row;
        int col;
    };

    struct ElemComp{
        bool operator()(const Elem& a, const Elem& b){
            return a.time > b.time;
        }
    };

    int swimInWaterDisjointSet(vector<vector<int>>& grid) {
        priority_queue<Elem, vector<Elem>, ElemComp> pq;
        size_t n = grid.size();
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                pq.emplace(grid[r][c], r, c);
            }
        }

        int t = 0;
        DisjointSet ds(n * n);
        while (ds.findByPos(0, 0) != ds.findByPos(n - 1, n - 1)) {
            Elem elem = pq.top();
            pq.pop();

            t = elem.time;
            int r = elem.row, c = elem.col;

            //ltf
            if (0 < c && grid[r][c - 1] <= t) {
                ds.mergeByPos(r, c, r, c - 1);
            }

            //top
            if (0 < r && grid[r - 1][c] <= t) {
                ds.mergeByPos(r, c, r - 1, c);
            }

            //rht
            if (c + 1 < n && grid[r][c + 1] <= t) {
                ds.mergeByPos(r, c, r, c + 1);
            }

            //btm
            if (r + 1 < n && grid[r + 1][c] <= t) {
                ds.mergeByPos(r, c, r + 1, c);
            }
        }

        return t;
    }

    int swimInWaterTraversal(vector<vector<int>>& grid) {
        size_t n = grid.size();
        vector<vector<bool>> seen(n, vector<bool>(n, false));

        int t = 0;
        priority_queue<Elem, vector<Elem>, ElemComp> pq;
        pq.emplace(grid[0][0], 0, 0);
        while (!pq.empty() && !seen[n - 1][n - 1]) {
            Elem elem = pq.top();
            pq.pop();

            int r = elem.row, c = elem.col;
            if (seen[r][c]) {
                continue;
            }

            seen[r][c] = true;
            t = max(t, elem.time);

            //ltf
            if (0 < c) {
                pq.emplace(grid[r][c - 1], r, c - 1);
            }

            //top
            if (0 < r) {
                pq.emplace(grid[r - 1][c], r - 1, c);
            }

            //rht
            if (c + 1 < n) {
                pq.emplace(grid[r][c + 1], r, c + 1);
            }

            //btm
            if (r + 1 < n) {
                pq.emplace(grid[r + 1][c], r + 1, c);
            }
        }

        return t;
    }

    int swimInWater(vector<vector<int>>& grid) {
        //return swimInWaterDisjointSet(grid);

        return swimInWaterTraversal(grid);
    }
};