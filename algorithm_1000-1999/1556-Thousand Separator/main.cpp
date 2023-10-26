class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0) {
            return "0";
        }

        string ret;
        for (; n; n /= 10) {
            ret.push_back('0' + n % 10);
            if ((ret.size() + 1) % 4 == 0) {
                ret.push_back('.');
            }
        }
        if (ret.back() == '.') {
            ret.pop_back();
        }

        std::reverse(ret.begin(), ret.end());

        return ret;
    }
};
