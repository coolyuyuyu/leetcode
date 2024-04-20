class Solution {
public:
    int scoreOfString(string s) {
        int ret = 0;
        for (int i = 1; i < s.size(); ++i) {
            ret += std::abs(s[i] - s[i - 1]);
        }

        return ret;
    }
};
