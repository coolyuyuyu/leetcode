class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0;
        for (char c : std::to_string(n)) {
            if (c == '0') { continue; }
            x = x * 10 + (c - '0');
            sum += (c - '0');
        }

        return x * sum;
    }
};
