class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<int> digits;
        for (int num = n; num; num /= 10) {
            digits.push_back(num % 10);
        }
        std::reverse(digits.begin(), digits.end());

        vector<int> cnts(10, 0);
        std::function<int(int, bool, int)> generate = [&](int pos, bool gt, int curNum) {
            if (pos >= digits.size()) {
                if (curNum <= n) { return 0; }
                for (int i = 0; i < cnts.size(); ++i) {
                    if (cnts[i] > 0 && cnts[i] != i) {
                        return 0;
                    }
                }
                return curNum > n ? curNum : 0;
            }

            for (int d = (gt ? 1 : digits[pos]); d <= digits.size(); ++d) {
                ++cnts[d];
                int ret = generate(pos + 1, gt || d > digits[pos], curNum * 10 + d);
                if (ret > 0) {
                    return ret;
                }
                --cnts[d];
            }

            return 0;
        };


        int ret = generate(0, false, 0);
        if (ret == 0) {
            digits.assign(digits.size() + 1, 1);
            ret = generate(0, false, 0);
        }

        return ret;
    }
};
