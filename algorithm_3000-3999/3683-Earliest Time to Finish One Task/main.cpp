class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ret = INT_MAX;
        for (const auto& task : tasks) {
            int s = task[0], t = task[1];
            ret = std::min(ret, s + t);
        }

        return ret;
    }
};
