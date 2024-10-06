class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnts[60];
        std::fill(cnts, cnts + 60, 0);

        int ret = 0;
        for (int t : time) {
            int r = t % 60;
            if (r == 0) {
                ret += cnts[r];
            }
            else {
                ret += cnts[60 - r];
            }

            ++cnts[r];
        }

        return ret;
    }
};
