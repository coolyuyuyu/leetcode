class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(
            intervals.begin(),
            intervals.end(),
            [](const auto& i1, const auto& i2) {
                if (i1[0] != i2[0]) {
                    return i1[0] < i2[0];
                }
                else {
                    return i1[1] > i2[1];
                }
            }
        );

        int ret = 0;
        for (int i = 0, n = intervals.size(); i < n; ++ret) {
            //++ret;
            int j = i + 1;
            while (j < n && intervals[i][1] >= intervals[j][1]) {
                ++j;
            }
            i = j;
        }
        return ret;
    }
};
