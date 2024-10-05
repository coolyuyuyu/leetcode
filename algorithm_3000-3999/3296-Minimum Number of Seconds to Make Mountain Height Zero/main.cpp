class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();

        // <next round start time, the number of time worker reduce, worker index>
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, std::greater<tuple<long long, int, int>>> pq;
        for (int i = 0; i < n; ++i) {
            pq.emplace(workerTimes[i], 1, i);
        }

        long long ret = 0;
        for (; 0 < mountainHeight--;) {
            auto [t, cnt, i] = pq.top();
            pq.pop();

            ret = std::max(ret, t);

            pq.emplace(t + 1LL * (cnt + 1) * workerTimes[i], cnt + 1, i);
        }

        return ret;
    }
};
