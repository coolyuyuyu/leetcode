class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> cnts(26, 0);
        for (char c : s) {
            if (c != '?') {
                ++cnts[c - 'a'];
            }
        }

        string candidates;
        for (char c : s) {
            if (c == '?') {
                auto itr = std::min_element(cnts.begin(), cnts.end());
                char c = 'a' + std::distance(cnts.begin(), itr);
                candidates.push_back(c);
                ++cnts[c - 'a'];
            }
        }
        std::sort(candidates.begin(), candidates.end());

        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (s[i] == '?') {
                s[i] = candidates[j++];
            }
        }

        return s;
    }
};
