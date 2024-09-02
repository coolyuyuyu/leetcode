class Solution {
public:
    int numberOfSubstrings(string s) {
        // the length of s <= 4 * 10^4
        // => the maximum number of 0s of a valid substring is 200

        int n = s.size();

        int cntRhtConsec1[n + 1];
        cntRhtConsec1[n] = 0;
        for (int i = n; 0 < i--;) {
            if (s[i] == '1') {
                cntRhtConsec1[i] = cntRhtConsec1[i + 1] + 1;
            }
            else {
                cntRhtConsec1[i] = 0;
            }
        }

        int ret = 0;
        for (int m = 1; m <= 200; ++m) {
            for (int lft = 0, rht = 0, cnt0 = 0; lft < n; ++lft) {
                for (; rht < n && cnt0 < m; ++rht) {
                    cnt0 += (s[rht] == '0' ? 1 : 0);
                }
                if (cnt0 < m) { break; }

                // ... [0 ... 0] 1 1 1 ...
                //      L        R

                int len = rht - lft;
                int cnt1 = len - m;
                if (cntRhtConsec1[rht] + cnt1 >= cnt0 * cnt0) {
                    int extra = cntRhtConsec1[rht] - std::max(cnt0 * cnt0 - cnt1, 0);
                    ret += std::max(extra + 1, 0);
                }

                cnt0 -= (s[lft] == '0' ? 1 : 0);
            }
        }

        for (int i = 0; i < n; ++i) {
            ret += cntRhtConsec1[i];
        }

        return ret;
    }
};
