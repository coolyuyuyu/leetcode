class Solution {
public:
    int M = 1e9 + 7;

    int quickPow(int base, int exp) {
        int ret = 1;
        for (; exp; exp >>= 1) {
            if (exp & 1) {
                ret = 1L * ret * base % M;
            }
            base = 1L * base * base % M;
        }

        return ret;
    }

    int inv(int num) {
        return quickPow(num, M - 2);
    }

    int numberOfSequence(int n, vector<int>& sick) {
        int fact[n], power2[n];
        fact[0] = 1, power2[0] = 1;
        for (int i = 1; i < n; ++i) {
            fact[i] = 1L * fact[i - 1] * i % M;
            power2[i] = 1L * power2[i - 1] * 2 % M;
        }

        vector<int> cnts;
        cnts.push_back(sick[0]);
        for (int i = 1; i < sick.size(); ++i) {
            cnts.push_back(sick[i] - sick[i - 1] - 1);
        }
        cnts.push_back(n - 1 - sick.back());

        int ret = fact[n - sick.size()];
        for (int cnt : cnts) {
            ret = 1L * ret * inv(fact[cnt]) % M;
        }

        for (int i = 1; i < sick.size(); ++i) {
            int cnt = sick[i] - sick[i - 1] - 1;
            if (cnt == 0) { continue;}
            ret = 1L * ret * power2[cnt - 1] % M;
        }

        return ret;
    }
};
