class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> intervals;
        for (int i = 0; i < ranges.size(); ++i) {
            intervals.emplace_back(std::max(0, i - ranges[i]), std::min(n, i + ranges[i]));
        }
        std::sort(intervals.begin(), intervals.end(), [](const auto& i1, const auto& i2) { return i1.first < i2.first; });

        int m = n + 1;
        int far = 0;
        int ret = 0;
        for (int i = 0; i < m;) {
            int nextFar = far;
            while (i < m && intervals[i].first <= far) {
                nextFar = std::max(nextFar, intervals[i].second);
                ++i;
            }
            if (far == nextFar) {
                return -1;
            }

            ++ret;
            if (n <= nextFar) {
                return ret;
            }

            far = nextFar;
        }

        return -1;
    }
};
