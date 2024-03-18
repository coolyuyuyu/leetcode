class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();

        std::function<string(string, string)> add = [](string num1, string num2) {
            std::reverse(num1.begin(), num1.end());
            std::reverse(num2.begin(), num2.end());

            string sum;
            int carry = 0;
            for (int i = 0, n = std::max<int>(num1.size(), num2.size()); i < n; ++i) {
                if (i < num1.size()) {
                    carry += num1[i] - '0';
                }
                if (i < num2.size()) {
                    carry += num2[i] - '0';
                }
                sum.push_back('0' + carry % 10);
                carry /= 10;
            }
            if (carry) {
                sum.push_back('0' + carry);
            }

            std::reverse(sum.begin(), sum.end());
            return sum;
        };

        std::function<bool(int, int, int)> dfs = [&](int len1, int len2, int i) {
            if (i >= n) {
                return true;
            }

            string num1 = num.substr(i - len1 - len2, len1);
            string num2 = num.substr(i - len2, len2);
            string sum = add(num1, num2);
            if (num.compare(i, sum.size(), sum) == 0) {
                return dfs(len2, sum.size(), i + sum.size());
            }

            return false;
        };
        for (int len1 = 1; len1 + 1 < n; ++len1) {
            if (len1 >= 2 && num[0] == '0') { continue; }
            for (int len2 = 1; len1 + len2 < n; ++len2) {
                if (len2 >= 2 && num[len1] == '0') { continue; }
                if (dfs(len1, len2, len1 + len2)) {
                    return true;
                }
            }
        }

        return false;
    }
};
