class Solution {
public:
    long long kMirror(int k, int n) {
        std::function<long long(int, bool)> buildPalindrome = [&](int num, bool f) {
            long long lft = num;
            long long rht = 0;
            int cnt = 0;
            for (long long tmp = lft; tmp; tmp /= 10, ++cnt) {
                rht *= 10;
                rht += (tmp % 10);
            }

            if (!f) {
                lft /= 10;
            }

            for (int i = 0; i < cnt; ++i) {
                lft *= 10;
            }

            return lft + rht;
        };

        vector<int> digits;
        std::function<bool(long long)> checkKMirror = [&](long long num) {
            digits.clear();
            for (long long tmp = num; tmp; tmp /= k) {
                digits.push_back(tmp % k);
            }

            for (int lft = 0, rht = digits.size() - 1; lft < rht; ++lft, --rht) {
                if (digits[lft] != digits[rht]) {
                    return false;
                }
            }

            return true;
        };

        vector<long long> rets;
        for (int len = 1; rets.size() < n; ++len) {
            int lo = std::pow(10, len - 1), hi = std::pow(10, len) - 1;
            for (int i = lo; i <= hi && rets.size() < n; ++i) {
                long long num = buildPalindrome(i, false);
                if (checkKMirror(num)) {
                    rets.push_back(num);
                }
            }

            for (int i = lo; i <= hi && rets.size() < n; ++i) {
                long long num = buildPalindrome(i, true);
                if (checkKMirror(num)) {
                    rets.push_back(num);
                }
            }
        }

        return std::accumulate(rets.begin(), rets.end(), 0LL);
    }
};
