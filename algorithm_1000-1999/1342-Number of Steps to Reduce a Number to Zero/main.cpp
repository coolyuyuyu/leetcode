class Solution {
public:
    int numberOfSteps_Intuition(int num) {
        int n = 0;
        while (num) {
            if (num & 1) {
                --num;
            }
            else {
                num >>= 1;
            }
            ++n;
        }
        return n;
    }

    int numberOfSteps_Count(int num) {
        if (num == 0) {
            return 0;
        }

        int n = 0;
        int mask = 1;
        for (int mask = 1; mask <= num; mask <<= 1) {
            if (num & mask) {
                n += 2;
            }
            else {
                n += 1;
            }
        }

        return n - 1;
    }

    int numberOfSteps(int num) {
        //return numberOfSteps_Intuition(num);
        return numberOfSteps_Count(num);
    }
};