class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> frees;
        frees.push_back(startTime.front());
        for (int i = 1; i < startTime.size(); ++i) {
            frees.push_back(startTime[i] - endTime[i - 1]);
        }
        frees.push_back(eventTime - endTime.back());

        int ret = 0;

        ++k;
        for (int i = 0, n = frees.size(), sum = 0; i < n; ++i) {
            sum += frees[i];
            if (i >= k) {
                sum -= frees[i - k];
            }

            ret = std::max(ret, sum);
        }

        return ret;
    }
};
