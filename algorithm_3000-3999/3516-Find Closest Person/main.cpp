class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d1 = std::abs(z - x), d2 = std::abs(z - y);
        if (d1 < d2) {
            return 1;
        }
        else if (d1 == d2) {
            return 0;
        }
        else {
            return 2;
        }
    }
};
