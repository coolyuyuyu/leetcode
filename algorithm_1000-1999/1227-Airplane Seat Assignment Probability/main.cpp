class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        // the probability that kth person's seat is occupied: 1 / (n - (k - 2))
        // the probability that kth person'gets his own seat: 1 - 1 / (n - (k - 2))
        return n > 1 ? 0.5 : 1.0;
    }
};
