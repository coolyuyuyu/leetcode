class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ret = 0;
        for (int i = 0, n = colors.size(); i < n; ++i) {
            int lft = ((i - 1) + n) % n;
            int rht = (i + 1) % n;
            if (colors[lft] != colors[i] && colors[i] != colors[rht]) {
                ++ret;
            }
        }

        return ret;
    }
};
