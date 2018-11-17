class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCnt = 0;
        int tenCnt = 0;
        for (int bill : bills) {
            switch (bill) {
            case 5:
                ++fiveCnt;
                break;
            case 10:
                if (fiveCnt == 0) {
                    return false;
                }
                --fiveCnt;
                ++tenCnt;
                break;
            case 20:
                if (tenCnt > 0 && fiveCnt > 0) {
                    --tenCnt;
                    --fiveCnt;
                }
                else if (fiveCnt >= 3) {
                    fiveCnt -= 3;
                }
                else {
                    return false;
                }
                break;
            }
        }

        return true;
    }
};