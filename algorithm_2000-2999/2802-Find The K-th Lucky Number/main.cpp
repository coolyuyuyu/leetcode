class Solution {
public:
    string kthLuckyNumber(int k) {
        ++k;

        string ret;
        for (; k > 1; k /= 2) {
            ret += (k & 1) ? "7" : "4";
        }
        std::reverse(ret.begin(), ret.end());

        return ret;
    }
};
