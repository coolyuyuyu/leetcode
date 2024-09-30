class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        --k;

        int step = 0;
        long long n = 1;
        while (n <= k) {
            n *= 2;
            ++step;
        }

        int shift = 0;
        for (int i = step; 0 < i--; n /= 2) {
            if (k >= n / 2) {
                k -= n / 2;
                if (operations[i] == 1) {
                    ++shift;
                }
            }
        }

        return 'a' + shift % 26;
    }
};
