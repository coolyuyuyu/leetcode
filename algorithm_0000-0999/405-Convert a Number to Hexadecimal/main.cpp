class Solution {
public:
    string toHex(int num) {
        string result;
        result.reserve(8);
        for (int i = 0; i < 8 && num != 0; ++i) {
            int n = num % 16;
            if (n < 0) {
                n += 16;
            }
            result.push_back(static_cast<char>(10 <= n ? ('a' + n - 10) : ('0' + n)));
            num >>= 4;
        }
        reverse(result.begin(), result.end());

        if (result.empty()) {
            result.push_back('0');
        }
        return result;
    }
};