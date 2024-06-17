class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();

        vector<int> cnts(24, 0);

        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            int h = hours[i] % 24;
            if (h == 0) {
                ret += cnts[0];
            }
            else {
                ret += cnts[24 - h];
            }

            ++cnts[h];
        }

        return ret;
    }
};
