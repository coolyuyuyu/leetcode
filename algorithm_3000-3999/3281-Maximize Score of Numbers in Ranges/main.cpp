class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        std::sort(start.begin(), start.end());

        std::function<bool(int)> checkScore = [&](int target) {
            int pre = INT_MIN;
            for (int i = 0; i < n; ++i) {
                if (0L + pre + target < start[i]) {
                    pre = start[i];
                }
                else if (0L + pre + target <= start[i] + d) {
                    pre = pre + target;
                }
                else {
                    return false;
                }
            }

            return true;
        };

        int lo = 0, hi = start.back() + d - start.front();
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (checkScore(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
