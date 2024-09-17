class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        int times[n];
        for (int i = 0; i < n; ++i) {
            times[i] = (timePoints[i][0] - '0') * 600 + (timePoints[i][1] - '0') * 60 + (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0') * 1;
        }
        std::sort(times, times + n);

        int ret = times[0] + 1440 - times[n - 1];
        for (int i = 1; i < n; ++i) {
            ret = std::min(ret, times[i] - times[i - 1]);
        }

        return ret;
    }
};
