class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        size_t n = startTime.size();

        map<int, int> dp; // dp[i]: max profit starting from time i

        vector<size_t> indexes(n);
        std::iota(indexes.begin(), indexes.end(), 0);
        std::sort(indexes.begin(), indexes.end(), [&](size_t i, size_t j) { return startTime[i] < startTime[j]; });

        int ans = 0;
        for (size_t i = n; 0 < i--;) {
            auto itr = dp.lower_bound(endTime[indexes[i]]);
            ans = std::max(ans, (itr == dp.end() ? 0 : itr->second) + profit[indexes[i]]);
            dp[startTime[indexes[i]]] = ans;
        }

        return ans;
    }
};
