class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long n = 1;
        int steps = 0;
        while (n < k) {
            n *= 2;
            ++steps;
        }

        int shift = 0;
        for (int i = steps - 1; i >= 0; --i, n /= 2) {
            if (k > n / 2) {
                k = k - n / 2;
                if (operations[i] == 1) {
                    ++shift;
                }
            }
        }

        return 'a' + (shift % 26);
    }
};
