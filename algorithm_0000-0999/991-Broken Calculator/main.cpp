class Solution {
public:
    int iterative(int x, int y) {
        int cnt = 0;
        while (y > x) {
            (y & 1) ? (y += 1) : (y /= 2);
            ++cnt;
        }

        return cnt + x - y;
    }

    int recursive(int x, int y) {
        if (x >= y) {
            return x - y;
        }
        else if (y % 2 == 0) {
            return 1 + recursive(x, y / 2);
        }
        else {
            return 1 + recursive(x, y + 1);
        }
    }

    int brokenCalc(int startValue, int target) {
        // return iterative(startValue, target);
        return recursive(startValue, target);
    }
};
