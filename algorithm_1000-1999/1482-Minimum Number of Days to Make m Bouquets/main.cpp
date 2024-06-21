class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m > n / k) { return -1; }

        std::function<bool(int)> checkOk = [&](int days) {
            int cnt = 0;
            for (int lft = 0; lft < n; ++lft) {
                if (bloomDay[lft] > days) { continue; }

                int rht = lft;
                while (rht + 1 < n && bloomDay[rht + 1] <= days) {
                    ++rht;
                }

                cnt += (rht - lft + 1) / k;
                if (cnt >= m) {
                    return true;
                }

                lft = rht;
            }

            return false;
        };

        int lo = 1, hi = *std::max_element(bloomDay.begin(), bloomDay.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (checkOk(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
