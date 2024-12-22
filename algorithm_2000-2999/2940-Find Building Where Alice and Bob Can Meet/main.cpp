class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int m = heights.size(), n = queries.size();

        for (int j = 0; j < n; ++j) {
            if (queries[j][0] > queries[j][1]) {
                std::swap(queries[j][0], queries[j][1]);
            }
        }

        int queryIndexes[n];
        std::iota(queryIndexes, queryIndexes + n, 0);
        std::sort(queryIndexes, queryIndexes + n, [&](int idx1, int idx2){ return queries[idx1][1] < queries[idx2][1]; });

        vector<int> ret(n, -1);
        map<int, int> height2idx;
        for (int i = m - 1, j = n - 1; j >= 0; --j) {
            int qIdx = queryIndexes[j], a = queries[qIdx][0], b = queries[qIdx][1];
            for (; i > b; --i) {
                while (!height2idx.empty() && heights[i] >= height2idx.begin()->first) {
                    height2idx.erase(height2idx.begin());
                }
                height2idx[heights[i]] = i;
            }

            if (a == b || heights[a] < heights[b]) {
                ret[qIdx] = b;
            }
            else {
                auto itr = height2idx.upper_bound(heights[a]);
                if (itr != height2idx.end()) {
                    ret[qIdx] = itr->second;
                }
            }
        }

        return ret;
    }
};
