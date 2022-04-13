class Solution {
public:
    // Time: O(MlogM + NlogN)
    int findContentChildren_Sort(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int cnt = 0;
        for (size_t i = 0, j = 0; i < g.size() && j < s.size();) {
            if (g[i] <= s[j]) {
                ++i; ++j;
                ++cnt;
            }
            else {
                ++j;
            }
        }

        return cnt;
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        return findContentChildren_Sort(g, s);
    }
};
