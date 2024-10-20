class Solution {
public:
    int minConnectedGroups(vector<vector<int>>& intervals, int k) {
        std::sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> merged;
        for (int i = 0; i < intervals.size();) {
            int j = i + 1;
            int maxR = intervals[i][1];
            for (; j < intervals.size() && maxR >= intervals[j][0]; ++j) {
                maxR = std::max(maxR, intervals[j][1]);
            }
            merged.emplace_back(intervals[i][0], maxR);

            i = j;
        }
        for (const auto [l, r] : merged) {
            cout << l << " " << r << endl;
        }

        int n = merged.size();
        int ret = n;
        for (int i = 0; i + 1 < n; ++i) {
            auto itr = std::upper_bound(merged.begin() + i, merged.end(), pair<int, int>{merged[i].second + k, INT_MAX});
            int cnt = std::distance(merged.begin() + i, itr);
            ret = std::min(ret, n - cnt + 1);
        }

        return ret;
    }
};
