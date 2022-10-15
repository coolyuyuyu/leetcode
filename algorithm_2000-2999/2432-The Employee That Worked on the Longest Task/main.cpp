class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int minId = logs.front()[0];
        int maxTime = logs.front()[1];
        for (size_t i = 1; i < logs.size(); ++i) {
            int time = logs[i][1] - logs[i - 1][1];
            if (maxTime < time) {
                maxTime = time;
                minId = logs[i][0];
            }
            else if (maxTime == time) {
                if (logs[i][0] < minId) {
                    minId = logs[i][0];
                }
            }
        }
        return minId;
    }
};
