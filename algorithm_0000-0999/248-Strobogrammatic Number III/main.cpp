class Solution {
public:
    vector<pair<char, char>> pairs = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    int strobogrammaticInRange(string low, string high) {
        int ret = 0;

        std::function<void(string&, int, int)> dfs = [&](string& s, int lft, int rht) {
            if (lft > rht) {
                if (s.size() == low.size() && s < low) {}
                else if (s.size() == high.size() && s > high) {}
                else {
                    ++ret;
                }
                return;
            }

            for (const auto& [c1, c2] : pairs) {
                if (s.size() > 1 && lft == 0 && c1 == '0') {
                    continue;
                }
                if (lft == rht && c1 != c2) {
                    continue;
                }
                s[lft] = c1;
                s[rht] = c2;
                dfs(s, lft + 1, rht - 1);
            }
        };

        for (int len = low.size(); len <= high.size(); ++len) {
            string s(len, ' ');
            dfs(s, 0, len - 1);
        }

        return ret;
    }
};
