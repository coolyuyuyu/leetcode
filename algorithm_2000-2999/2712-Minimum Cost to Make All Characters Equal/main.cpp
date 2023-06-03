class Solution {
public:
    long long greedy1(const string& s) {
        int n = s.size();

        long long ret = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] != s[i])
            ret += std::min(i, n - i);
        }

        return ret;
    }

    long long greedy2(const string& s) {
        int n = s.size();
        auto minimumCost = [&](char c) {
            if (n == 0) {
                return 0LL;
            }

            vector<long long> lft(n);
            lft[0] = (s[0] != c ? 1 : 0);
            for (int i = 1; i < n; ++i) {
                lft[i] = lft[i - 1];
                if (s[i] != c) {
                    if (s[i] == s[i - 1]) {
                        lft[i] += 1;
                    }
                    else {
                        lft[i] += (i + 1);
                        lft[i] += i;
                    }
                }
            }

            vector<long long> rht(n);
            rht[n - 1] = (s[n - 1] != c ? 1 : 0);
            for (int i = n - 1; 0 < i--;) {
                rht[i] = rht[i + 1];
                if (s[i] != c) {
                    if (s[i] == s[i + 1]) {
                        rht[i] += 1;
                    }
                    else {
                        rht[i] += (n - i);
                        rht[i] += (n - i - 1);
                    }
                }
            }

            long long ret = LLONG_MAX;
            for (int i = 0; i <= n; ++i) {
                long long cost = 0;
                if (0 < i) {
                    cost += lft[i - 1];
                }
                if (i < n) {
                    cost += rht[i];
                }
                ret = std::min(ret, cost);
            }

            return ret;
        };

        return std::min(minimumCost('0'), minimumCost('1'));
    }

    long long minimumCost(string s) {
        return greedy1(s);
        //return greedy2(s);
    }
};
