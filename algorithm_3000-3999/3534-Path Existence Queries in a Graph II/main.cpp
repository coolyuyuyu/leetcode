class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int idxs[n];
        std::iota(idxs, idxs + n, 0);
        std::sort(idxs, idxs + n, [&](int idx1, int idx2){ return nums[idx1] < nums[idx2]; });

        int node2idx[n];
        for (int i = 0; i < n; ++i) {
            node2idx[idxs[i]] = i;
        }

        int m = std::numeric_limits<unsigned>::digits - __builtin_clz(n);

        int nxts[n][m];
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && nums[idxs[j]] - nums[idxs[i]] <= maxDiff) {
                ++j;
            }
            nxts[i][0] = j - 1;
        }

        for (int k = 1; k < m; ++k) {
            for (int v = 0; v < n; ++v) {
                nxts[v][k] = nxts[nxts[v][k - 1]][k - 1];
            }
        }

        vector<int> ret(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int u = node2idx[queries[i][0]], v = node2idx[queries[i][1]];
            if (u == v) {
                ret[i] = 0;
                continue;
            }

            if (u > v) {
                std::swap(u, v);
            }

            int steps = 0;
            for (int k = m; 0 < k--;) {
                if (nxts[u][k]< v) {
                    u = nxts[u][k];
                    steps += 1 << k;
                }
            }
            ret[i] = nxts[u][0] >= v ? steps + 1: -1;
        }

        return ret;
    }
};
