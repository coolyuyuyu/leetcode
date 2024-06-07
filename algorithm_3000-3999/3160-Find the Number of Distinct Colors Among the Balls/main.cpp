class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int, int> id2color;
        unordered_map<int, int> color2cnt;

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            int x = queries[i][0], y = queries[i][1];
            if (id2color.find(x) != id2color.end()) {
                if (--color2cnt[id2color[x]] == 0) {
                    color2cnt.erase(id2color[x]);
                }
            }
            id2color[x] = y;
            ++color2cnt[y];

            ret[i] = color2cnt.size();
        }

        return ret;
    }
};
