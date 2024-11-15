class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int m = items.size();
        std::sort(items.begin(), items.end());

        int n = queries.size();
        int indexes[n];
        std::iota(indexes, indexes + n, 0);
        std::sort(indexes, indexes + n, [&](int idx1, int idx2) { return queries[idx1] < queries[idx2]; });

        vector<int> ret(n);
        for (int i = 0, j = 0, mx = 0; i < n; ++i) {
            int idx = indexes[i];
            for (; j < m && items[j][0] <= queries[idx]; ++j) {
                mx = std::max(mx, items[j][1]);
            }
            ret[idx] = mx;
        }

        return ret;
    }
};
