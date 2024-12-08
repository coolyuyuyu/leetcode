class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        std::function<bool(int)> f = [&](int target) {
            long long cnt = 0;
            for (int candie : candies) {
                cnt += (candie / target);
                if (cnt >= k) {
                    return true;
                }
            }
            return false;
        };

        int lo = 0, hi = *std::max_element(candies.begin(), candies.end());
        while (lo < hi) {
            int mid = hi - (hi - lo) / 2;
            if (f(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};
