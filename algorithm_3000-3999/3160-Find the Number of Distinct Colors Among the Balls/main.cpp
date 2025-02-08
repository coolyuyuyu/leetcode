class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball2color, color2cnt;
        vector<int> ret(queries.size());
        for (int i = 0, diffCnt = 0; i < queries.size(); ++i) {
            int x = queries[i][0], y = queries[i][1];
            if (ball2color.find(x) != ball2color.end()) {
                if(--color2cnt[ball2color[x]] == 0) {
                    --diffCnt;
                }
            }
            ball2color[x] = y;
            if (++color2cnt[y] == 1) {
                ++diffCnt;
            }

            ret[i] = diffCnt;
        }

        return ret;
    }
};
