class Solution {
public:
    int math1(int n) {
        int ret = 0;
        for (int i = 1; i * i <= n; ++i) {
            ++ret;
        }

        return ret;
    }

    int math2(int n) {
        return floor(sqrt(n));
    }

    int bulbSwitch(int n) {
        //return math1(n);
        return math2(n);
    }
};
