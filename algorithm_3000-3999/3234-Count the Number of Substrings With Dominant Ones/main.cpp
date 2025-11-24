class Solution {
public:
    int numberOfSubstrings(string s) {
        // s.length <= 4 * 1e4
        // => the maximum number of 0 is 200

        int n = s.size();
        int total0 = std::count(s.begin(), s.end(), '0'), total1 = n - total0;

        int cntRhtConsec1[n + 1];
        cntRhtConsec1[n] = 0;
        for (int i = n; 0 < i--;) {
            cntRhtConsec1[i] = s[i] == '0' ? 0 : (cntRhtConsec1[i + 1] + 1);
        }

        int ret = 0;

        // substring of all 1's
        for (int i = 0; i < n; ++i) {
            ret += cntRhtConsec1[i];
        }

        for (int m = 1; m <= std::min(200, total0); ++m) {
            for (int l = 0, r = 0, cnt0 = 0; l < n; ++l) {
                for (; r < n && cnt0 < m; ++r) {
                    cnt0 += (s[r] == '0' ? 1 : 0);
                }
                if (cnt0 < m) { break; }

                // ... [0 ... 0] 1 1 1 ...
                //      L        R

                int len = r - l;
                int cnt1 = len - cnt0;
                if (cntRhtConsec1[r] + cnt1 >= cnt0 * cnt0) {
                    int extra = cntRhtConsec1[r] - std::max(cnt0 * cnt0 - cnt1, 0);
                    ret += std::max(extra + 1, 0);
                }

                cnt0 -= (s[l] == '0' ? 1 : 0);
            }
        }


        return ret;
    }
};
