class Solution {
public:
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29};

    static const int M = 1e9 + 7;

    static int modPlus(int num1, int num2) {
        return (num1 + num2) % M;
    }

    static int modMinus(int num1, int num2) {
        return (((num1 - num2) % M) + M) % M;
    }

    bool computeState(int num, int& state) {
        state = 0;
        for (int i = 0; i < primes.size(); ++i) {
            if ((num % (primes[i] * primes[i])) == 0) {
                return false;
            }

            if ((num % primes[i]) == 0) {
                state |= (1 << i);
            }
        }

        return true;
    }

    int squareFreeSubsets(vector<int>& nums) {
        int n = 1 << primes.size();

        vector<int> counts(n, 0);
        counts[0] = 1;
        for (int num : nums) {
            int state;
            if (!computeState(num, state)) {
                continue;
            }

            for (int i = 0; i < n; ++i) {
                if ((i & state) == state) {
                    counts[i] = modPlus(counts[i], counts[i - state]);
                }
            }
        }

        int ret = std::accumulate(counts.begin(), counts.end(), 0, modPlus);
        ret = modMinus(ret, 1); // empty
        return ret;
    }
};
