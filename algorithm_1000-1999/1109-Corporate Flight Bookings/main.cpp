class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int diff[n + 1];
        std::fill(diff, diff + n + 1, 0);

        for (const auto& booking : bookings) {
            int first = booking[0] - 1, last = booking[1] - 1, seats = booking[2];
            diff[first] += seats;
            diff[last + 1] -= seats;
        }

        vector<int> ret(n);
        for (int i = 0, sum = 0; i < n; ++i) {
            sum += diff[i];
            ret[i] = sum;
        }

        return ret;
    }
};
