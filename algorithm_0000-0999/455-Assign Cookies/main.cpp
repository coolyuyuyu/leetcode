class Solution {
public:
    // Time: O(MlogM + NlogN)
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size(), n = s.size();

        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int ret = 0;
        for (int i = 0, j = 0; i < m && j < n;) {
            if (g[i] <= s[j]) {
                ++i, ++j;
                ++ret;
            }
            else {
                ++j;
            }
        }

        return ret;
    }
};
