class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int m = n / 2;

        vector<int> cnts(26, 0);
        for (int i = 0; i < m; ++i) {
            ++cnts[s[i] - 'a'];
        }

        std::function<int(int, int, int)> computeComb = [&](int n, int r, int limit) {
            r = min(r, n - r);

            int res = 1;
            for (int i = n - r + 1, j = r; i <= n; ++i) {
                if (numeric_limits<int>::max() / i < res) { return limit; };

                res *= i;
                while (j > 0 && res % j == 0) {
                    res /= j;
                    --j;
                }

                if (j == 0 && res >= limit) return limit;
            }

            return res;
        };
        std::function<int(int)> countPerms = [&](int limit) {
            long long ret = 1;
            for (int i = 0, total = std::accumulate(cnts.begin(), cnts.end(), 0); i < 26; ++i) {
                if (cnts[i] == 0) { continue; }

                ret *= computeComb(total, cnts[i], limit);
                if (ret >= limit) {
                    return limit;
                }
                total -= cnts[i];
            }

            return (int)ret;
        };

        if (countPerms(k) < k) {
            return "";
        }

        string half;
        for (int i = 0; i < m; ++i) {
            int j;
            for (j = 0; j < 26; ++j) {
                if (cnts[j] == 0) { continue; }

                --cnts[j];
                int cntPerm = countPerms(k);
                if (cntPerm < k) {
                    ++cnts[j];
                    k -= cntPerm;
                }
                else {
                    half.push_back('a' + j);
                    break;
                }
            }
        }

        string ret = half;
        if (n & 1) {
            ret += s[m];
        }
        std::copy(half.rbegin(), half.rend(), std::back_inserter(ret));

        return ret;
    }
};
