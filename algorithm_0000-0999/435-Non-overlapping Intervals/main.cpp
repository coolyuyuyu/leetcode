class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const auto& i1, const auto& i2) { return i1[1] < i2[1]; });

        int ret = 0;
        for (size_t i = 0; i < intervals.size();) {
            size_t j = i + 1;
            for (; j < intervals.size() && intervals[j][0] < intervals[i][1]; ++j) {
                ++ret;
            }
            i = j;
        }

        return ret;
    }
};
