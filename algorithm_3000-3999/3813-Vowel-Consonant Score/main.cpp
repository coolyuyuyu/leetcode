class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        for (char ch : s) {
            if (!std::isalpha(ch)) { continue; }
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                ++v;
            }
            else {
                ++c;
            }
        }

        int ret = 0;
        if (c) {
            ret = std::floor(1.0 * v / c);
        }

        return ret;
    }
};
