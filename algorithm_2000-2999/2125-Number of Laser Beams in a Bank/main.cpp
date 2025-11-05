class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ret = 0;
        for (int i = 0, n = bank.size(), preCnt = 0; i < n; ++i) {
            int curCnt = std::count(bank[i].begin(), bank[i].end(), '1');
            if (curCnt) {
                ret += preCnt * curCnt;
                preCnt = curCnt;
            }
        }

        return ret;
    }
};
