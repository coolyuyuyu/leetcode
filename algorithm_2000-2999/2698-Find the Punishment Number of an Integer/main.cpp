class Solution {
public:
    int punishmentNumber(int n) {
        std::function<vector<int>(int)> toDigits = [](int num) {
            vector<int> ret;
            for (; num; num /= 10) {
                ret.push_back(num % 10);
            }
            std::reverse(ret.begin(), ret.end());
            return ret;
        };

        std::function<bool(int, const vector<int>&)> checkOk = [](int target, const vector<int>& digits) {
            for (int state = 0, n = digits.size(); state < (1 << (n - 1)); ++state) {
                int sum = 0;
                for (int i = 0, j = 0; i < n; i = j) {
                    int num = 0;
                    for (; j < n && ((state >> i) & 1) == ((state >> j) & 1); ++j) {
                        num = num * 10 + digits[j];
                    }
                    sum += num;
                }

                if (sum == target) {
                    return true;
                }
            }
            return false;
        };

        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            vector<int> digits = toDigits(square);
            if (checkOk(i, toDigits(square))) {
                ret += square;
            }
        }

        return ret;
    }
};
