class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size();

        pair<int, int> job[n];
        for (int i = 0; i < n; ++i) {
            job[i] = {difficulty[i], profit[i]};
        }
        std::sort(job, job + n, [](const auto& j1, const auto& j2){ return j1.second < j2.second; });

        std::sort(worker.begin(), worker.end());

        int ret = 0;
        for (int j = m - 1, i = n - 1; i >= 0 && j >= 0;) {
            auto& [d, p] = job[i];
            if (d <= worker[j]) {
                ret += p;
                --j;
            }
            else {
                --i;
            }
        }

        return ret;
    }
};
