class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights);
        std::sort(expected.begin(), expected.end());

        int ret = 0;
        for (int i = 0, n = heights.size(); i < n; ++i) {
            if (heights[i] != expected[i]) {
                ++ret;
            }
        }

        return ret;
    }
};
