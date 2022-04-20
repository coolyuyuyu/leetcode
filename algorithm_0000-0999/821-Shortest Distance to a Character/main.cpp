class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> dists(s.size());
        for (int prev = 0 - s.size(), i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                prev = i;
            }
            dists[i] = i - prev;
        }

        for (int prev = 2 * s.size(), i = s.size(); 0 < i--;) {
            if (s[i] == c) {
                prev = i;
            }
            dists[i] = std::min(dists[i], prev - i);
        }

        return dists;
    }
};
