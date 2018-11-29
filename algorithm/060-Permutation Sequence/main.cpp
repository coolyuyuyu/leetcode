class Solution {
public:
    string getPermutation(int n, int k) {
        long long f = 1;
        for (int i = 2; i <= n; ++i) {
            f *= i;
        }

        string ans;
        vector<bool> used(n, false);
        for (; 0 < n; --n) {
            f /= n;

            int times = k / f - (k % f == 0 ? 1 : 0);
            k -= (times * f);
            for (int i = 0; i < used.size(); ++i) {
                if (used[i]) {
                    continue;
                }

                if (times == 0) {
                    used[i] = true;
                    ans += to_string(i + 1);
                    break;
                }
                --times;
            }
        }

        return ans;
    }
};