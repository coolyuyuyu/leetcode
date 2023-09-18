class Solution {
public:
    vector<int> bySort(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        vector<pair<int, int>> pairs(m); // <cnt, idx>
        for (int r = 0; r < m; ++r) {
            pairs[r] = {std::distance(mat[r].begin(), std::find(mat[r].begin(), mat[r].end(), 0)), r};
        }
        std::partial_sort(pairs.begin(), pairs.begin() + k, pairs.end());

        vector<int> ret(k);
        for (int i = 0; i < k; ++i) {
            ret[i] = pairs[i].second;
        }

        return ret;
    }

    vector<int> byHeap(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat.empty() ? 0 : mat[0].size();

        priority_queue<pair<int, int>> pq; // <cnt, idx>
        for (int r = 0; r < m; ++r) {
            pq.emplace((int)std::distance(mat[r].begin(), std::find(mat[r].begin(), mat[r].end(), 0)), r);
            if (k < pq.size()) {
                pq.pop();
            }
        }

        vector<int> ret(k);
        for (int i = k; 0 < i--; pq.pop()) {
            ret[i] = pq.top().second;
        }

        return ret;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        //return bySort(mat, k);
        return byHeap(mat, k);
    }
};
