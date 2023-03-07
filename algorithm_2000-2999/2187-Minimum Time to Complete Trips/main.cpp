class Solution {
public:
    bool canAchieve(const vector<int>& time, long long totalTimes, int targetTotalTrips) {
        long long totalTrips = 0;
        for (int t : time) {
            totalTrips += (totalTimes / t);
            if (targetTotalTrips <= totalTrips) {
                return true;
            }
        }

        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo = 0, hi = 1e14;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canAchieve(time, mid, totalTrips) ) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
