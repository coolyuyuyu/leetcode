class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        auto cmp = [](const vector<int>& task1, const vector<int>& task2) {
            return task1[1] - task1[0] < task2[1] - task2[0];
        };
        std::sort(tasks.begin(), tasks.end(), cmp);

        int ret = 0;
        for (const auto& task : tasks) {
            int actual = task[0], minimum = task[1];
            ret = std::max(ret + actual, minimum);
        }

        return ret;
    }
};
