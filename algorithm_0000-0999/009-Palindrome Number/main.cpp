class Solution {
public:
    int reverse(int x) {
        bool positive = (x >= 0);
        int y = 0;
        while (x) {
            if (positive) {
                if (y > ((numeric_limits<int>::max() - (x % 10)) / 10)) {
                    return 0;
                }
            }
            else {
                if (y < ((numeric_limits<int>::min() - (x % 10)) / 10)) {
                    return 0;
                }
            }
            y = y * 10 + x % 10;
            x = x / 10;
        }

        return y;
    }

    bool isPalindrome_compareReverse(int x) {
        return x >= 0 && x == reverse(x);
    }

    bool isPalindrome_checkEndsInward(int x) {
        if (x <= 0) {
            return x == 0;
        }

        int n = static_cast<int>(floor(log10(x))) + 1;
        int maskMSD = pow(10, n - 1);
        for (int i = 0; i < (n / 2); ++i) {
            if (x / maskMSD != x % 10) {
                return false;
            }
            x %= maskMSD;
            x /= 10;
            maskMSD /= 100;
        }

        return true;
    }


    bool isPalindrome(int x) {
        //return isPalindrome_compareReverse(x);
        return isPalindrome_checkEndsInward(x);
    }
};