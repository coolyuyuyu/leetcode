class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freqs(10, 0);
        for (; n; n /= 10) {
            ++freqs[n % 10];
        }

        int ret = 0;
        for (int d = 0; d < 10; ++d) {
            ret += d * freqs[d];
        }

        return ret;
    }
};
