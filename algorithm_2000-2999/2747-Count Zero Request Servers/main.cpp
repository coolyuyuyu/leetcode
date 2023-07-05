class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        std::sort(logs.begin(), logs.end(), [](const auto& log1, const auto& log2) { return log1[1] < log2[1]; });

        vector<int> qIndexes(queries.size());
        std::iota(qIndexes.begin(), qIndexes.end(), 0);
        std::sort(qIndexes.begin(), qIndexes.end(), [&](int i1, int i2) { return queries[i1] < queries[i2]; });

        vector<int> cnts(n, 0);

        vector<int> ret(queries.size());
        for (int lft = 0, rht = 0, numNonEmpty = 0, i = 0; i < queries.size(); ++i) {
            int query = queries[qIndexes[i]];
            while (rht < logs.size() && logs[rht][1] <= query) {
                if (cnts[logs[rht][0] - 1]++ == 0) {
                    ++numNonEmpty;
                }
                ++rht;
            }
            while (lft < logs.size() && logs[lft][1] < (query - x)) {
                if (--cnts[logs[lft][0] - 1] == 0) {
                    --numNonEmpty;
                }
                ++lft;
            }

            ret[qIndexes[i]] = n - numNonEmpty;
        }

        return ret;
    }
};
