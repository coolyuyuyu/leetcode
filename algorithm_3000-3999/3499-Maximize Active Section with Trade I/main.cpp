class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int cnt1 = 0;
        vector<tuple<char, int, int>> segs;
        for (int i = 0, n = s.size(); i < n; ++i) {
            segs.emplace_back(s[i], i, i);
            auto& [type, bgnIdx, endIdx] = segs.back();
            while (endIdx + 1 < n && s[bgnIdx] == s[endIdx + 1]) {
                ++endIdx;
            }
            if (type == '1') {
                cnt1 += (endIdx - bgnIdx + 1);
            }
            i = endIdx;
        }

        int mxGain = 0;
        for (int i = 1; i + 1 < segs.size(); ++i) {
            auto& [type, bgnIdx, endIdx] = segs[i];
            if (type == '0') { continue; }

            auto& [lftType, lftBgnIdx, lftEndIdx] = segs[i - 1];
            auto& [rhtType, rhtBgnIdx, rhtEndIdx] = segs[i + 1];
            mxGain = std::max(mxGain, (lftEndIdx - lftBgnIdx + 1) + (rhtEndIdx - rhtBgnIdx + 1));
        }

        return cnt1 + mxGain;
    }
};
