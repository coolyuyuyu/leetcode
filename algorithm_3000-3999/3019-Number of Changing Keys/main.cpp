class Solution {
public:
    int countKeyChanges(string s) {
        int ret = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (std::tolower(s[i - 1]) != std::tolower(s[i])) {
                ++ret;
            }
        }

        return ret;
    }
};
