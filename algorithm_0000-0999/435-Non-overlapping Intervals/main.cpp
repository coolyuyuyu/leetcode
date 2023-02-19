class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& i1, const vector<int>& i2) { return i1[1] < i2[1]; });

        size_t count = 0;
        for (size_t i = 0; i < intervals.size();) {
            size_t j = i + 1;
            while (j < intervals.size() && intervals[j][0] < intervals[i][1]) {
                ++j;
            }
            count += (j - i - 1);
            i = j;
        }

        return count;
    }
};
