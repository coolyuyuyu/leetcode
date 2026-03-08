class Solution {
public:
    int totalDistance(string s) {
        vector<string> keyboard = {
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm",
        };

        unordered_map<char, pair<int, int>> key2pos;
        for (int r = 0; r < keyboard.size(); ++r) {
            for (int c = 0; c < keyboard[r].size(); ++c) {
                key2pos[keyboard[r][c]] = {r, c};
            }
        }

        s.insert(s.begin(), 'a');
        int ret = 0;
        for (int i = 1; i < s.size(); ++i) {
            auto [r1, c1] = key2pos[s[i - 1]];
            auto [r2, c2] = key2pos[s[i]];
            ret += std::abs(r2 - r1) + std::abs(c2 - c1);
        }

        return ret;
    }
};
