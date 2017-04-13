class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int result = 0;
        int sIndex = 0;
        for (int gIndex = 0; gIndex < g.size(); ++gIndex) {
            while (sIndex < s.size() && s[sIndex] < g[gIndex]) {
                ++sIndex;
            }

            if (sIndex < s.size()) {
                ++result;
                ++sIndex;
            }
            else {
                break;
            }
        }

        return result;
    }
};