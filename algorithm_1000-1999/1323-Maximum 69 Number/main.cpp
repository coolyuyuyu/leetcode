class Solution {
public:
    int maximum69Number (int num) {
        int diff = 0;
        for (int tmpNum = num, tmpDiff = 3; tmpNum; tmpNum /= 10, tmpDiff *= 10) {
            if (tmpNum % 10 == 6) {
                diff = tmpDiff;
            }
        }
        num += diff;

        return num;
    }
};
