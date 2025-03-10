class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ret = 0;
        for (int i = 0, n = colors.size(), len = 1; i < n + k - 2; ++i) {
            len = (colors[i % n] != colors[(i + 1) % n]) ? (len + 1) : 1;
            ret += (len >= k ? 1 : 0);
        }

        return ret;
    }
};
