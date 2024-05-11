class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        pair<int, int> worker[n];
        for (int i = 0; i < n; ++i) {
            worker[i] = {quality[i], wage[i]};
        }
        std::sort(
            worker, worker + n,
            [](const auto& w1, const auto& w2) {
                return 1.0 * w1.second / w1.first < 1.0 * w2.second / w2.first;
            });

        priority_queue<int> maxPQ;
        int total = 0;

        double ret = DBL_MAX;
        for (int i = 0; i < n; ++i) {
            if (maxPQ.size() >= k) {
                total -= maxPQ.top();
                maxPQ.pop();
            }

            double unitWage = 1.0 * worker[i].second / worker[i].first;
            if (maxPQ.size() == k - 1) {
                ret = std::min(ret, unitWage * (total + worker[i].first));
            }

            maxPQ.push(worker[i].first);
            total += worker[i].first;
        }

        return ret;
    }
};
