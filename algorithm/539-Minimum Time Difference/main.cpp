class Solution {
public:
    size_t findMinDifference(vector<string>& timePoints) {
        vector<size_t> mins(timePoints.size());
        for (size_t i = 0; i < mins.size(); ++i) {
            mins[i] = (timePoints[i][0] - '0') * 600 + (timePoints[i][1] - '0') * 60 + (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0') * 1;
        }
        sort(mins.begin(), mins.end());

        size_t minDiff = numeric_limits<size_t>::max();
        for (size_t i = 1; i < mins.size(); ++i) {
            minDiff = min(minDiff, mins[i] - mins[i - 1]);
        }
        minDiff = min(minDiff, mins.front() + 1440 - mins.back());

        return minDiff;
    }
};