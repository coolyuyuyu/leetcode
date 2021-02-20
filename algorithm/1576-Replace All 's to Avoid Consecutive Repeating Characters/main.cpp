class Solution {
public:
    string modifyString(string s) {
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != '?') {
                continue;
            }

            vector<char> neighbors;
            if (i + 1 < s.size() && s[i + 1] != '?') {
                neighbors.emplace_back(s[i + 1]);
            }
            if (0 < i && s[i - 1] != '?') {
                neighbors.emplace_back(s[i - 1]);
            }
            for (char c = 'a'; true; c += 1) {
                if (find(neighbors.begin(), neighbors.end(), c) == neighbors.end()) {
                    s[i] = c;
                    break;
                }
            }
        }

        return s;
    }
};