class Solution {
public:
    string findContestMatch(int n) {
        vector<string> matches(n);
        for (int i = 0; i < n; ++i) {
            matches[i] = std::to_string(i + 1);
        }

        while (matches.size() > 1) {
            vector<string> tmp(matches.size() / 2);
            for (int i = 0; i < tmp.size(); ++i) {
                tmp[i] = "(" + matches[i] + "," + matches[matches.size() - i - 1] + ")";
            }
            matches.swap(tmp);
        }

        return matches[0];
    }
};
