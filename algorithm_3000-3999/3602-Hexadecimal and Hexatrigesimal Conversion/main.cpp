class Solution {
public:
    string concatHex36(int n) {
        string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        string base16 = "";
        for (int num = n * n; num; num /= 16) {
            base16 += chars[num % 16];
        }
        std::reverse(base16.begin(), base16.end());

        string base36 = "";
        for (int num = n * n * n; num; num /= 36) {
            base36 += chars[num % 36];
        }
        std::reverse(base36.begin(), base36.end());

        return base16 + base36;
    }
};
