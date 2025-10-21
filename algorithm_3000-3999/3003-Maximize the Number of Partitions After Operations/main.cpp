class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();

        vector<tuple<int, int, int>> pre(n);
        for (int i = 0, partCnt = 0, mask = 0, diffCnt = 0; i + 1 < n; ++i) {
            int idx = s[i] - 'a';
            if (((mask >> idx) & 1) == 0) {
                if (++diffCnt > k) {
                    partCnt += 1;
                    mask = (1 << idx);
                    diffCnt = 1;
                }
                else {
                    mask |= (1 << idx);
                }
            }
            pre[i + 1] = {partCnt, mask, diffCnt};
        }

        vector<tuple<int, int, int>> suf(n);
        for (int i = n - 1, partCnt = 0, mask = 0, diffCnt = 0; i > 0; --i) {
            int idx = s[i] - 'a';
            if (((mask >> idx) & 1) == 0) {
                if (++diffCnt > k) {
                    partCnt += 1;
                    mask = (1 << idx);
                    diffCnt = 1;
                }
                else {
                    mask |= (1 << idx);
                }
            }
            suf[i - 1] = {partCnt, mask, diffCnt};
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            const auto& [lftPartCnt, lftMask, lftDiffCnt] = pre[i];
            const auto& [rhtPartCnt, rhtMask, rhtDiffCnt] = suf[i];
            int partCnt = lftPartCnt + 1 + rhtPartCnt;
            int diffCnt = __builtin_popcount(lftMask | rhtMask);
            int add = std::min(diffCnt + 1, 26) <= k ? 0 : ((lftDiffCnt == k && rhtDiffCnt == k && diffCnt < 26) ? 2 : 1);
            ret = std::max(ret, partCnt + add);
        }

        return ret;
    }
};
