class Solution {
public:
    int M = 1e9 + 7;

    int quickPow(int base, int exp) {
        int ret = 1;
        for (; exp; exp >>= 1) {
            if (exp & 1) {
                ret = (1L * ret * base) % M;
            }
            base = (1L * base * base) % M;
        }

        return ret;
    };

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<tuple<int, int, int>> pres(n);
        for (int i = 0, x = 0, sum = 0, cnt = 0; i < n; ++i) {
            char c = s[i];
            if (c > '0') {
                x = (1LL *x * 10 % M + (c - '0')) % M;
                sum = (sum + (c - '0')) % M;
                cnt = (cnt + 1) % M;
            }
            pres[i] = {x, sum, cnt};
        }

        vector<int> ret(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int l = queries[i][0], r = queries[i][1];

            auto [lftX, lftSum, lftCnt] = l > 0 ? pres[l -   1] : tuple<int,int,int>{0, 0, 0};
            auto [rhtX, rhtSum, rhtCnt] = pres[r];

            int x = ((rhtX - 1LL * lftX * quickPow(10, rhtCnt - lftCnt) % M) + M) % M;
            int sum = ((rhtSum - lftSum) + M) % M ;
            ret[i] = 1LL * x * sum % M;
        }

        return ret;
    }
};
