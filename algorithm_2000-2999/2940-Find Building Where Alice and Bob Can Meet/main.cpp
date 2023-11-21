class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = queries.size();

        for (int i = 0; i < n; ++i) {
            if (queries[i][0] > queries[i][1]) {
                std::swap(queries[i][0], queries[i][1]);
            }
            queries[i].push_back(i);
        }
        std::sort(queries.begin(), queries.end(), [](const auto& query1, const auto& query2){ return query1[1] < query2[1]; });

        map<int, int> height2idx;

        vector<int> ret(queries.size());
        int hIdx = heights.size() - 1;
        for (int i = queries.size(); 0 < i--;) {
            int a = queries[i][0], b = queries[i][1], qIdx = queries[i][2];
            for (; b < hIdx; --hIdx) {
                while (!height2idx.empty() && heights[hIdx] >= height2idx.begin()->first) {
                    height2idx.erase(height2idx.begin());
                }
                height2idx[heights[hIdx]] = hIdx;
            }

            if (a == b || heights[a] < heights[b]) {
                ret[qIdx] = b;
            }
            else {
                auto itr = height2idx.upper_bound(std::max(heights[a], heights[b]));
                ret[qIdx] = (itr == height2idx.end() ? -1 : itr->second);
            }
        }

        return ret;
    }
};
