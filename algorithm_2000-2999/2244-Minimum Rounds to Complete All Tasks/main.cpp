class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnts;
        for (int task : tasks) {
            ++cnts[task];
        }

        int ret = 0;
        for (auto [_, freq] : cnts) {
            if (freq == 1) {
                return -1;
            }

            ret += (freq + 2) / 3;
            /*
            int numOf3 = freq / 3;
            if ((numOf3 % 2) == (freq % 2)) {
                ret += numOf3;
                ret += ((freq - (numOf3 * 3)) / 2);
            }
            else {
                ret += (numOf3 - 1);
                ret += ((freq - (numOf3 - 1) * 3) / 2);
            }
            */
        }

        return ret;
    }
};
