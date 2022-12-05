class Solution {
public:
    long long M = 1e9+7;

    // Time: O(300n), Space: O(200n)
    int v0(const string& s) {
        size_t n = s.size();

        vector<int> cntLft(10, 0); ++cntLft[s.front() - '0'];
        vector<vector<vector<long long>>> dpLft(n, vector<vector<long long>>(10, vector<long long>(10, 0)));
        for (size_t i = 1; i < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    dpLft[i][j][k] += dpLft[i - 1][j][k];
                    if (k == (s[i] - '0')) {
                        dpLft[i][j][k] = (dpLft[i][j][k] + cntLft[j]) % M;
                    }
                }
            }
            ++cntLft[s[i] - '0'];
        }

        vector<int> cntRht(10, 0); ++cntRht[s.back() - '0'];
        vector<vector<vector<long long>>> dpRht(n, vector<vector<long long>>(10, vector<long long>(10, 0)));
        for (size_t i = n - 1; 0 < i--;) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    dpRht[i][j][k] = dpRht[i + 1][j][k];
                    if (k == (s[i] - '0')) {
                        dpRht[i][j][k] = (dpRht[i][j][k] + cntRht[j]) % M;;
                    }
                }
            }
            ++cntRht[s[i] - '0'];
        }

        long long ret = 0;
        for (size_t i = 1; (i + 1) < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    ret = (ret + dpLft[i - 1][j][k] * dpRht[i + 1][j][k]) % M;
                }
            }
        }

        return ret;
    }

    // Time: O(200n), Space: O(200n)
    int v1(const string& s) {
        size_t n = s.size();

        vector<int> cntLft(10, 0), cntRht(10, 0);
        ++cntLft[s.front() - '0'];
        ++cntRht[s.back() - '0'];

        long long dpLft[n][10][10], dpRht[n][10][10];
        memset(dpLft, 0, sizeof(dpLft)), memset(dpRht, 0, sizeof(dpRht));

        for (size_t lft = 1, rht = n - 2; lft < n; ++lft, --rht) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    dpLft[lft][j][k] = dpLft[lft - 1][j][k];
                    dpRht[rht][j][k] = dpRht[rht + 1][j][k];
                }
                dpLft[lft][j][s[lft] - '0'] = (dpLft[lft][j][s[lft] - '0'] + cntLft[j]) % M;
                dpRht[rht][j][s[rht] - '0'] = (dpRht[rht][j][s[rht] - '0'] + cntRht[j]) % M;
            }
            ++cntLft[s[lft] - '0'];
            ++cntRht[s[rht] - '0'];
        }

        long long ret = 0;
        for (size_t i = 1; (i+1) < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    ret = (ret + dpLft[i - 1][j][k] * dpRht[i + 1][j][k]) % M;
                }
            }
        }

        return ret;
    }

    int countPalindromes(string s) {
        //return v0(s);
        return v1(s);
    }
};

/*
* ! X ! *

dpLft[i][j][k]: how many subsequence {j, k} of string s[:i+1]
dpRht[i][j][k]: how many subsequence {j, k} of string s[i:] reversely

X X X X X
        i
dp[i][j][k] += dp[i-1][j][k];
if (s[i] == k) {
    dp[i][j][k] +=count[i-1][j]
}
*/
