class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();

        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            int heights[n];
            long long sum;

            heights[i] = maxHeights[i];
            sum = heights[i];
            for (int j = i; 0 < j--;) {
                heights[j] = std::min(maxHeights[j], heights[j + 1]);
                sum += heights[j];
            }
            for (int j = i + 1; j < n; ++j) {
                heights[j] = std::min(maxHeights[j], heights[j - 1]);
                sum += heights[j];
            }

            ret = std::max(ret, sum);
        }

        return ret;
    }
};
