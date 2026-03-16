class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();

        // <time worker starts next round, number of times worker reduce the height, worker index>
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, std::greater<>> pq;
        for (int i = 0; i < n; ++i) {
            pq.emplace(workerTimes[i], 0, i);
        }

        long long ret = 0;
        while (0 < mountainHeight--) {
            auto [t, cnt, i] = pq.top();
            pq.pop();

            ret = std::max(ret, t);

            ++cnt;
            pq.emplace(t + 1LL * (cnt + 1) * workerTimes[i], cnt, i);
        }

        return ret;
    }
};
