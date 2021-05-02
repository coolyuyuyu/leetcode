class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted(heights);
        sort(sorted.begin(), sorted.end());

        int count = 0;
        for (size_t i = 0; i < heights.size(); ++i) {
            if (sorted[i] != heights[i]) {
                ++count;
            }
        }

        return count;
    }
};
