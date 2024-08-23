class Solution {
public:
    string fractionAddition(string expression) {
        vector<pair<int, int>> fractions;
        for (int i = 0, n = expression.size(); i < n;) {
            int sign = 1;
            switch (expression[i]) {
            case '+':
                ++i;
                break;
            case '-':
                sign = -1;
                ++i;
                break;
            default:
                break;
            }

            int p = 0;
            for (; i < n && std::isdigit(expression[i]); ++i) {
                p *= 10;
                p += expression[i] - '0';
            }

            assert(expression[i] == '/');
            ++i;

            int q = 0;
            for (; i < n && std::isdigit(expression[i]); ++i) {
                q *= 10;
                q += expression[i] - '0';
            }

            fractions.emplace_back(sign * p, q);
        }

        int denominator = 1;
        for (const auto& [_, q] : fractions) {
            denominator = std::lcm(denominator, q);
        }

        int numerator = 0;
        for (const auto& [p, q] : fractions) {
            denominator = std::lcm(denominator, q);
            numerator += (p * denominator / q);
        }

        if (numerator == 0) {
            return "0/1";
        }

        int g = std::gcd(numerator, denominator);
        return std::to_string(numerator / g) + "/" + std::to_string(denominator / g);
    }
};
