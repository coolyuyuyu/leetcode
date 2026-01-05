class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int, int>> ranges;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int j = i;
            while (j + 1 < n && nums[j] <= nums[j + 1]) { ++j; }
            ranges.emplace_back(i, j);
            i = j;
        }
        int n = ranges.size();

        long long cnts[n];
        for (int i = 0; i < n; ++i) {
            auto [l, h] = ranges[i];
            int len = h - l + 1;
            cnts[i] = 1LL * (len) * (len + 1) / 2;
        }
        long long precnts[n];
        std::partial_sum(cnts, cnts + n, precnts);
        std::function<long long(int, int)> sumcnt = [&](int l, int h) {
            if (l > h) { return 0LL; }
            return precnts[h] - (l > 0 ? precnts[l - 1] : 0);
        };

        vector<long long> ret(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int l = queries[i][0], r = queries[i][1];
            int idxL = std::distance(ranges.begin(), std::upper_bound(ranges.begin(), ranges.end(), pair<int,int>{l, INT_MAX})) - 1;
            int idxR = std::distance(ranges.begin(), std::upper_bound(ranges.begin(), ranges.end(), pair<int,int>{r, INT_MAX})) - 1;
            if (idxL < idxR) {
                int lenL = ranges[idxL].second - l + 1;
                int lenR = r - ranges[idxR].first + 1;
                ret[i] = 1LL * (lenL) * (lenL + 1) / 2 + sumcnt(idxL + 1, idxR - 1) + 1LL * (lenR) * (lenR + 1) / 2;
            }
            else {
                int len = r - l + 1;
                ret[i] = 1LL * (len) * (len + 1) / 2;
            }
        }

        return ret;
    }
};
