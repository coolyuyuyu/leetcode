class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt1 = __builtin_popcount(num1), cnt2 = __builtin_popcount(num2);

        int ret = num1;
        if (cnt1 > cnt2) {
            int cnt = cnt1 - cnt2;
            for (int i = 0, cnt = cnt1 - cnt2; i < 32 && cnt; ++i) {
                if (((ret >> i) & 1) == 1) {
                    ret &= ~(1 << i);
                    --cnt;
                }
            }
        }
        else if (cnt1 < cnt2){
            int cnt = cnt2 - cnt1;
            for (int i = 0, cnt = cnt2 - cnt1; i < 32 && cnt; ++i) {
                if (((ret >> i) & 1) == 0) {
                    ret |= (1 << i);
                    --cnt;
                }
            }
        }

        return ret;
    }
};
