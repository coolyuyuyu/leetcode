class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        int ret = 0;

        vector<int> frees;
        frees.push_back(startTime[0]);
        for (int i = 1; i < n; ++i) {
            frees.push_back(startTime[i] - endTime[i - 1]);
        }
        frees.push_back(eventTime - endTime[n - 1]);

        ++k;
        for (int i = 0, sum = 0; i < frees.size(); ++i) {
            sum += frees[i];
            if (i + 1 >= k) {
                ret = std::max(ret, sum);
                sum -= frees[i + 1 - k];
            }
        }

        return ret;
    }
};
