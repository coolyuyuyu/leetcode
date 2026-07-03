class Solution {
public:
    double angleClock(int hour, int minutes) {
        double y = minutes * 6;
        double x = hour * 30 + y / 360 * 30;
        double diff = std::abs(x - y);
        return std::min(diff, 360 - diff);
    }
};
