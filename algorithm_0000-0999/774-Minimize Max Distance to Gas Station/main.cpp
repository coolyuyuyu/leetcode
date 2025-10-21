class Solution {
public:
    // Time: O: (N + logM * N), M: largest distance between two stations
    double bsearch(const vector<int>& stations, int k) {
        double lo = 0, hi = 0;
        for (int i = 1; i < stations.size(); ++i) {
            hi = std::max<double>(hi, stations[i] - stations[i - 1]);
        }

        while (hi - lo > 1e-6) {
            double mid = (lo + hi) / 2;
            int cnt = 0;
            for (int i = 1; i < stations.size() && cnt <= k; ++i) {
                int dist = stations[i] - stations[i - 1];
                cnt += std::ceil(dist / mid) - 1;
            }
            if (cnt <= k) {
                hi = mid;
            }
            else {
                lo = mid;
            }
        }

        return lo;
    }

    // Time: O: (N + k * logN), TLE
    double greedy1(const vector<int>& stations, int k) {
        priority_queue<pair<double, int>> maxPQ; // <partDist, partCnt>
        for (int i = 1; i < stations.size(); ++i) {
            maxPQ.emplace(stations[i] - stations[i - 1], 1);
        }

        while (k-- > 0) {
            auto [partDist, partCnt] = maxPQ.top();
            maxPQ.pop();
            maxPQ.emplace(partDist * partCnt / (partCnt + 1), partCnt + 1);
        }

        return maxPQ.top().first;
    }

    // Time:
    double greedy2(const vector<int>& stations, int k) {
        double ub = static_cast<double>(stations.back() - stations.front()) / (k + 1);
        priority_queue<pair<double, int>> pq; // <distance per part, num of parts>
        for (int i = 1; i < stations.size(); ++i) {
            double dist = stations[i] - stations[i - 1];
            int parts = std::max<int>(dist / ub, 1);
            k -= (parts - 1);
            pq.emplace(dist / parts, parts);
        }

        while (0 < k--) {
            auto [dist, parts] = pq.top();
            pq.pop();

            pq.emplace(dist * parts / (parts + 1), parts + 1);
        }

        return pq.top().first;
    }

    double minmaxGasDist(vector<int>& stations, int k) {
        //return bsearch(stations, k);
        return greedy1(stations, k);
        //return greedy2(stations, k);
    }
};
