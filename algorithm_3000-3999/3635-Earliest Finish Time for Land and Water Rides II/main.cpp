class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size(), n = waterStartTime.size();

        int lEarliestFinished = INT_MAX;
        for (int i = 0; i < m; ++i) {
            lEarliestFinished = std::min(lEarliestFinished, landStartTime[i] + landDuration[i]);
        }

        int lwEarliestFinished = INT_MAX;
        for (int j = 0; j < n; ++j) {
            lwEarliestFinished = std::min(lwEarliestFinished, std::max(waterStartTime[j], lEarliestFinished) + waterDuration[j]);
        }

        int wEarliestFinished = INT_MAX;
        for (int j = 0; j < n; ++j) {
            wEarliestFinished = std::min(wEarliestFinished, waterStartTime[j] + waterDuration[j]);
        }

        int wlEarliestFinished = INT_MAX;
        for (int i = 0; i < m; ++i) {
            wlEarliestFinished = std::min(wlEarliestFinished, std::max(landStartTime[i], wEarliestFinished) + landDuration[i]);
        }

        return std::min(lwEarliestFinished, wlEarliestFinished);
    }
};
