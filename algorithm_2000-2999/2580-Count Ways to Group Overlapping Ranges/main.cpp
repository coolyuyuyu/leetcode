class Solution {
public:
    int M = 1e9 + 7;
    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size();

        std::sort(ranges.begin(), ranges.end());

        int ret = 1;
        for (int lft = 0, rht; lft < n; lft = rht) {
            int far = ranges[lft][1];
            for (rht = lft + 1; rht < n && ranges[rht][0] <= far; ++rht) {
                far = std::max(far, ranges[rht][1]);
            }

            ret = (ret * 2) % M;
        }

        return ret;
    }
};
