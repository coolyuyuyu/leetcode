class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        std::function<bool(int)> canFinish = [&](int speed) {
            int t = 0;
            for (int pile : piles) {
                t += (pile + (speed - 1)) / speed;
                if (t > h) { return false; }
            }

            return true;
        };

        int lo = 1, hi = *std::max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canFinish(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
