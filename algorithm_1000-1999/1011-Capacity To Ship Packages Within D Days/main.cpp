class Solution {
public:
    // binary search
    // O(nlogK)
    int shipWithinDays(vector<int>& weights, int days) {
        auto shippable = [&weights, days](int capacity) -> bool {
            int load = capacity + 1;
            int d = 0;
            for (int weight : weights) {
                if (capacity < weight) {
                    return false;
                }

                if ((load + weight) <= capacity) {
                    load += weight;
                }
                else if (d < days){
                    load = weight;
                    ++d;
                }
                else {
                    return false;
                }
            }

            return true;
        };

        int lo = 0, hi = 1e4 * 5 * 500;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (shippable(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
