class Solution {
public:
    int f1(int left, int right) {
        int ret = 0;
        for (int i = 31; i >= 0; --i) {
            int b1 = left >> i, b2 = right >> i;
            if (b1 != b2) {
                break;
            }
            ret |= b1 << i;
        }

        return ret;
    }

    int f2(int left, int right) {
        while (left < right) {
            right = right & (right - 1);
        }

        return right;
    }

    int rangeBitwiseAnd(int left, int right) {
        //return f1(left, right);
        return f2(left, right);
    }
};
