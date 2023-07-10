class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long n1 = num1, n2 = num2;

        for (int k = 0; k < 61; ++k) {
            long tmp = n1 - k*n2;
            if (__builtin_popcountll(tmp) <= k && k <= tmp) {
                return k;
            }
        }

        return -1;
    }
};

// num1 - (k*num2 + sum_k(2^i)) = 0
// => num1 - k*num2 = sum_k(2^i)
// => num1 - k*num2 = sum_k(2^i) >= k
// => bit_count(num1 - k*num2) <= k
