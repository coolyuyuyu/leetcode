class Solution {
public:
    bool completePrime(int num) {
        std::function<bool(int)> checkPrime = [](int num) {
            if (num == 1) { return false; }
            for (int i = 2, n = std::sqrt(num); i <= n; ++i) {
                if (num % i == 0) {
                    return false;
                }
            }

            return true;
        };

        string s = std::to_string(num);
        int pre = 0, suf = 0;
        for (int i = 0, n = s.size(); i + 1 < n; ++i) {
            pre = pre * 10 + s[i] - '0';
            if (!checkPrime(pre)) { return false; }
            suf = suf + (s[n - i - 1] - '0') * pow(10, i);
            if (!checkPrime(suf)) { return false; }
        }

        return checkPrime(num);
    }
};
