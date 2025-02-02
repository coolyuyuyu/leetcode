class Solution {
public:
    int maxDistance(string s, int k) {
        int t = 0, b = 0, l = 0, r = 0;
        int ret = 0;
        for (char c : s) {
            switch (c) {
                case 'N': ++t; break;
                case 'S': ++b; break;
                case 'E': ++r; break;
                case 'W': ++l; break;
            }

            ret = std::max(ret, std::abs(t - b) + std::abs(l - r) + 2 * std::min(std::min(t, b) + std::min(l, r), k));
        }

        return ret;
    }
};
