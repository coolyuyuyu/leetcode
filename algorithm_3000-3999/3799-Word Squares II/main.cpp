class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();

        vector<vector<string>> ret;
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < n; ++b) {
                if (b == a) { continue; }
                for (int c = 0; c < n; ++c) {
                    if (c == a || c == b) { continue; }
                    for (int d = 0; d < n; ++d) {
                        if (d == a || d == b || d == c) { continue; }

                        const auto& top = words[a];
                        const auto& lft = words[b];
                        const auto& rht = words[c];
                        const auto& btm = words[d];

                        if (top[0] != lft[0]) { continue; }
                        if (top[3] != rht[0]) { continue; }
                        if (btm[0] != lft[3]) { continue; }
                        if (btm[3] != rht[3]) { continue; }

                        ret.push_back({top, lft, rht, btm});
                    }
                }
            }
        }
        std::sort(ret.begin(), ret.end());

        return ret;
    }
};
