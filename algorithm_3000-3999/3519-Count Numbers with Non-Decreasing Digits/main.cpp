class Solution {
public:
    int M = 1e9 + 7;

    pair<vector<int>, int> divmod(const vector<int>& numer, int base, int denom) {
        vector<int> quot;
        int rem = 0;
        for (int num : numer) {
            int cur = rem * base + num;
            quot.push_back(cur / denom);
            rem = cur % denom;
        }
        quot.erase(quot.begin(), std::find_if(quot.begin(), quot.end(), [](int d){ return d != 0; }));

        return {quot, rem};
    }

    vector<int> convertBaseXtoBaseY(const vector<int>& num, int x, int y) {
        vector<int> ret;
        for (vector<int> quot = num; !quot.empty();) {
            int rem;
            std::tie(quot, rem) = divmod(quot, x, y);
            ret.push_back(rem);
        }
        while (!ret.empty() && ret.back() == 0) {
            ret.pop_back();
        }

        std::reverse(ret.begin(), ret.end());

        return ret;
    }

    vector<int> minus1(const vector<int>& num, int base) {
        assert(num != vector<int>{0});

        vector<int> ret = num;
        for (int i = ret.size(); 0 < i--;) {
            if (ret[i] > 0) {
                ret[i] -= 1;
                break;
            }
            else {
                ret[i] = base - 1;
            }
        }

        if (ret.size() > 1 && ret[0] == 0) {
            ret.erase(ret.begin());
        }

        return ret;
    }

    vector<int> toIntVec(const string& s) {
        vector<int> ret;
        for (char c : s) {
            ret.push_back(c - '0');
        }

        return ret;
    }

    int countNumbers(const vector<int>& num, int b) {
        int n = num.size();
        if (n == 0) {
            return 1;
        }

        int cache[b][n][2];
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 2; ++k) {
                    cache[i][j][k] = -1;
                }
            }
        }

        std::function<int(int, int, bool)> dfs = [&](int last, int pos, bool tight) {
            if (pos >= n) {
                return 1;
            }

            if (cache[last][pos][tight] != -1) {
                return cache[last][pos][tight];
            }

            int& ret = cache[last][pos][tight] = 0;
            for (int d = last, limit = tight ? num[pos] : (b - 1); d <= limit; ++d) {
                ret += dfs(d, pos + 1, tight && d == num[pos]);
                ret %= M;
            }
            return ret;
        };

        return dfs(0, 0, true);
    }

    int countNumbers(string l, string r, int b) {
        vector<int> lNum = minus1(toIntVec(l), 10), rNum = toIntVec(r);
        lNum = convertBaseXtoBaseY(lNum, 10, b);
        rNum = convertBaseXtoBaseY(rNum, 10, b);

        return ((countNumbers(rNum, b) - countNumbers(lNum, b)) % M + M) % M;
    }
};
