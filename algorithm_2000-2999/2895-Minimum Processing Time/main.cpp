class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int n = processorTime.size();

        std::sort(processorTime.begin(), processorTime.end());
        std::sort(tasks.begin(), tasks.end());

        vector<int> taskTime(n);
        for (int i = 0; i < n; ++i) {
            taskTime[i] = tasks[(i + 1) * 4 - 1];
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = std::max(ret, processorTime[i] + taskTime[n - i - 1]);
        }

        return ret;
    }
};
