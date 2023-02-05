class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        vector<vector<bool>> tbl(128, vector<bool>(128, false));
        for (const auto& mapping : mappings) {
            tbl[mapping[0]][mapping[1]] = true;
        }

        auto match = [&](char s, char t) -> bool {
            return s == t || tbl[t][s];
        };
        for (size_t i = 0; i + sub.size() <= s.size(); ++i) {
            if (std::equal(s.begin() + i, s.begin() + i + sub.size(), sub.begin(), match)) {
                return true;
            }
        }

        return false;
    }
};
