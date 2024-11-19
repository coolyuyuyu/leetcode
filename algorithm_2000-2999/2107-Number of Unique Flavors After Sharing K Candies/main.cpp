class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        unordered_map<int, int> cnts;
        int uniqueCnt = 0;
        for (int candy : candies) {
            if (++cnts[candy] == 1) {
                ++uniqueCnt;
            }
        }
        if (k == 0) {
            return uniqueCnt;
        }

        int ret = 0;
        for (int i = 0, n = candies.size(); i < n; ++i) {
            if (--cnts[candies[i]] == 0) {
                --uniqueCnt;
            }

            if (i + 1 >= k) {
                ret = std::max(ret, uniqueCnt);

                if (++cnts[candies[i + 1 - k]] == 1) {
                    ++uniqueCnt;
                }
            }
        }

        return ret;
    }
};
