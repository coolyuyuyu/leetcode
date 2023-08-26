class Solution {
public:
    int greedy1(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const auto& i1, const auto& i2) { return i1[1] < i2[1]; });

        int n = intervals.size();

        int maxNonOverlapping = 0;
        for (int i = 0; i < n;) {
            int j = i + 1;
            for (; j < n && intervals[i][1] > intervals[j][0]; ++j) {
                ;
            }
            ++maxNonOverlapping;

            i = j;
        }

        return n - maxNonOverlapping;
    }

    int greedy2(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const auto& i1, const auto& i2) { return i1[0] < i2[0]; });

        int n = intervals.size();

        int maxNonOverlapping = 0;
        int far = INT_MIN;
        for (const auto& interval : intervals) {
            if (far <= interval[0]) {
                far = interval[1];
                ++maxNonOverlapping;
            }
            else if (interval[1] < far) {
                far = interval[1];
            }
        }

        return n - maxNonOverlapping;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //return greedy1(intervals);
        return greedy2(intervals);
    }
};
