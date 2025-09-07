class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int, int> cnts;
        for (; n; n /= 10) {
            ++cnts[n % 10];
        }

        int minCnt = INT_MAX;
        int ret = -1;
        for (const auto& [d, cnt] : cnts) {
            if (cnt < minCnt) {
                minCnt = cnt;
                ret = d;
            }
            else if (cnt == minCnt) {
                ret = std::min(ret, d);
            }
        }

        return ret;
    }
};
