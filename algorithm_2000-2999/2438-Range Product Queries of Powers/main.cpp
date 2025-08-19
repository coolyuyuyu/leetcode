class Solution {
public:
    int M = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> exps;
        for (int i = 0; n; ++i, n >>= 1) {
            if (n & 1) {
                exps.push_back(i);
            }
        }

        vector<int> presums(exps.size());
        std::partial_sum(exps.begin(), exps.end(), presums.begin());

        std::function<int(int, int)> quickPow = [&](int base, int exp) {
            int ret = 1;
            for (; exp; exp >>= 1) {
                if (exp & 1) {
                    ret = (1L * ret * base) % M;
                }
                base = (1L * base * base) % M;
            }
            return ret;
        };

        int m = queries.size();
        vector<int> ret(m);
        for (int i = 0; i < m; ++i) {
            int lft = queries[i][0], rht = queries[i][1];
            int exp = presums[rht] - (lft > 0 ? presums[lft - 1] : 0);
            ret[i] = quickPow(2, exp);
        }

        return ret;
    }
};
