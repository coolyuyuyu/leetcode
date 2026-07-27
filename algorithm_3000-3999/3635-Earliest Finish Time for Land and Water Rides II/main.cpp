class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size(), n = waterStartTime.size();

        int lMin = INT_MAX;
        for (int i = 0; i < m; ++i) {
            lMin = std::min(lMin, landStartTime[i] + landDuration[i]);
        }
        int lwMin = INT_MAX;
        for (int j = 0; j < n; ++j) {
            lwMin = std::min(lwMin, std::max(lMin, waterStartTime[j]) + waterDuration[j]);
        }

        int wMin = INT_MAX;
        for (int j = 0; j < n; ++j) {
            wMin = std::min(wMin, waterStartTime[j] + waterDuration[j]);
        }
        int wlMin = INT_MAX;
        for (int i = 0; i < m; ++i) {
            wlMin = std::min(wlMin, std::max(wMin, landStartTime[i]) + landDuration[i]);
        }

        return std::min(lwMin, wlMin);
    }
};
