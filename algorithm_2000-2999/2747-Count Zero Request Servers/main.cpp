class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        std::sort(logs.begin(), logs.end(), [](const vector<int>& log1, const vector<int>& log2) { return log1[1] < log2[1]; });

        vector<int> qIndexes(queries.size());
        std::iota(qIndexes.begin(), qIndexes.end(), 0);
        std::sort(qIndexes.begin(), qIndexes.end(), [&](int qIdx1, int qIdx2) { return queries[qIdx1] < queries[qIdx2]; } );

        vector<int> cnts(n, 0);
        vector<int> ret(queries.size());
        for (int lft = 0, rht = 0, cntNonEmpty = 0, i = 0; i < qIndexes.size(); ++i) {
            int query = queries[qIndexes[i]];

            for (; rht < logs.size() && logs[rht][1] <= query; ++rht) {
                if (cnts[logs[rht][0] - 1]++ == 0) {
                    ++cntNonEmpty;
                }
            }

            for (; lft < logs.size() && logs[lft][1] < (query - x); ++lft) {
                if (--cnts[logs[lft][0] - 1] == 0) {
                    --cntNonEmpty;
                }
            }

            ret[qIndexes[i]] = n - cntNonEmpty;
        }

        return ret;
    }
};
