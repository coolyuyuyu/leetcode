class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();

        int ret = 0;
        for (int i = 0, preNonZeroCnt = 0; i < n; ++i) {
            int curNonZeroCnt = std::count(bank[i].begin(), bank[i].end(), '1');
            if (curNonZeroCnt > 0 ) {
                ret += curNonZeroCnt * preNonZeroCnt;
                preNonZeroCnt = curNonZeroCnt;
            }
        }

        return ret;
    }
};
