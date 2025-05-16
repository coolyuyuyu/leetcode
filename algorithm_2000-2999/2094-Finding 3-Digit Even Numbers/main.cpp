class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int cnts[10];
        std::fill(cnts, cnts + 10, 0);
        for (int d : digits) {
            ++cnts[d];
        }

        vector<int> ret;
        int tmps[10];
        for (int i = 100; i <= 999; i += 2) {
            std::fill_n(tmps, 10, 0);
            bool ok = true;
            for (int num = i; num; num /= 10) {
                int d = num % 10;
                if (++tmps[d] > cnts[d]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
