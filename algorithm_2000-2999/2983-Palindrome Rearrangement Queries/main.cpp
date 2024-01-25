class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n = s.size() / 2;

        string s2 = s.substr(n);
        std::reverse(s2.begin(), s2.end());
        string s1 = s.substr(0, n);
        s1 = "#" + s1;
        s2 = "#" + s2;

        int presum1[n + 1][26];
        int presum2[n + 1][26];
        for (char ch = 0; ch < 26; ++ch) {
            presum1[0][ch] = presum2[0][ch]  = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (char ch = 0; ch < 26; ++ch) {
                presum1[i][ch] = presum1[i - 1][ch] + ('a' + ch == s1[i] ? 1 : 0);
                presum2[i][ch] = presum2[i - 1][ch] + ('a' + ch == s2[i] ? 1 : 0);
            }
        }

        int diff[n + 1];
        diff[0] = 0;
        for (int i = 1; i <= n; ++i) {
            diff[i] = diff[i - 1] + (s1[i] != s2[i] ? 1 : 0);
        }

        std::function<bool(int, int, int, int)> check = [&](int a, int b, int c, int d) {
            // assume A: [a, b], B: [c, d];

            vector<pair<int, int>> AandB;
            if (std::max(a, c) <= std::min(b, d)) {
                AandB.emplace_back(std::max(a, c), std::min(b, d));
            }

            vector<pair<int, int>> AnotB, BnotA;
            if (AandB.empty()) {
                AnotB.emplace_back(a, b);
                BnotA.emplace_back(c, d);
            }
            else {
                if (a < c) { AnotB.emplace_back(a, c - 1); }
                if (d < b) { AnotB.emplace_back(d + 1, b); }
                if (b < d) { BnotA.emplace_back(b + 1, d); }
                if (c < a) { BnotA.emplace_back(c, a - 1); }
            }

            vector<pair<int, int>> AorB;
            for (const auto& p : AandB) {
                AorB.push_back(p);
            }
            for (const auto& p : AnotB) {
                AorB.push_back(p);
            }
            for (const auto& p : BnotA) {
                AorB.push_back(p);
            }

            int cntDiff = 0;
            for (const auto& [bgn, end] : AorB) {
                cntDiff += diff[end] - diff[bgn - 1];
            }
            if (cntDiff != diff[n]) {
                return false;
            }

            int cnt1[26], cnt2[26];
            for (char ch = 0; ch < 26; ++ch) {
                cnt1[ch] = presum1[b][ch] - presum1[a - 1][ch];
                for (const auto& [bgn, end] : AnotB) {
                    cnt1[ch] -= presum2[end][ch] - presum2[bgn - 1][ch];
                }
                if (cnt1[ch] < 0) {
                    return false;
                }

                cnt2[ch] = presum2[d][ch] - presum2[c - 1][ch];
                for (const auto& [bgn, end] : BnotA) {
                    cnt2[ch] -= presum1[end][ch] - presum1[bgn - 1][ch];
                }
                if (cnt2[ch] < 0) {
                    return false;
                }

                if (cnt1[ch] != cnt2[ch]) {
                    return false;
                }
            }

            return true;
        };

        vector<bool> ret(queries.size());
        for (int i = 0; i < ret.size(); ++i) {
            int a = queries[i][0] + 1;
            int b = queries[i][1] + 1;
            int c = n - 1 - (queries[i][3] - n) + 1;
            int d = n - 1 - (queries[i][2] - n) + 1;
            ret[i] = check(a, b, c, d);
        }

        return ret;
    }
};
