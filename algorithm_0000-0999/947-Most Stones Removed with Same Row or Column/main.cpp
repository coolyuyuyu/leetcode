class Solution {
public:
    int removeStones1(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<vector<bool>> adjMtx(n, vector<bool>(n, 0));
        for (size_t i = 0; i < stones.size(); ++i) {
            for (size_t j = i + 1; j < stones.size(); ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adjMtx[i][j] = true;
                    adjMtx[j][i] = true;
                }
            }
        }

        int ans = 0;

        vector<bool> seen(n, false);
        for (int i = 0; i < n; ++i) {
            if (seen[i]) {
                continue;
            }

            int componentSize = 0;

            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int j = q.front();
                q.pop();
                if (seen[j]) {
                    continue;
                }

                ++componentSize;
                seen[j] = true;
                for (int k = 0; k < n; ++k) {
                    if (adjMtx[j][k] && !seen[k]) {
                        q.push(k);
                    }
                }
            }

            ans += (componentSize - 1);
        }

        return ans;
    }

    class DisjointSet {
    public:
        DisjointSet(int size)
            : m_parents(size) {
            for (size_t i = 0; i < m_parents.size(); ++i) {
                m_parents[i] = i;
            }
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
            m_parents[rootI] = rootJ;
        }

    private:
        vector<int> m_parents;
    };

    int removeStones2(vector<vector<int>>& stones) {
        DisjointSet ds(20000);
        for (const vector<int>& stone : stones) {
            ds.merge(stone[0], stone[1] + 10000);
        }

        unordered_set<int> roots;
        for (const vector<int>& stone : stones) {
            roots.insert(ds.find(stone[0]));
        }

        return stones.size() - roots.size();
    }

    int removeStones(vector<vector<int>>& stones) {
        //return removeStones1(stones);

        return removeStones2(stones);
    }
};