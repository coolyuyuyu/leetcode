class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5 = 0, cnt10 = 0;
        for (int bill : bills) {
            switch (bill) {
            case 5:
                ++cnt5;
                break;
            case 10:
                if (cnt5-- == 0) {
                    return false;
                }
                ++cnt10;
                break;
            case 20:
                if (cnt10 > 0 && cnt5 > 0) {
                    --cnt10, --cnt5;
                }
                else if (cnt5 >= 3){
                    cnt5 -= 3;
                }
                else {
                    return false;
                }
                break;
            default:
                break;
            }
        }

        return true;
    }
};
