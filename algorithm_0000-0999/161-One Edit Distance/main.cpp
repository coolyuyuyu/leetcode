class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        for (int i = 0, n = std::min(s.size(), t.size()); i < n; ++i) {
            if (s[i] == t[i]) { continue; }
            if (s.size() == t.size()) { 
                return s.compare(i + 1, string::npos, t, i + 1, string::npos) == 0;
            }
            else if (s.size() > t.size()) {
                return s.compare(i + 1, string::npos, t, i, string::npos) == 0;
            }
            else {
                return s.compare(i, string::npos, t, i + 1, string::npos) == 0;
            }
        }

        return s.size() + 1 == t.size() || s.size() == t.size() + 1;
    }
};
