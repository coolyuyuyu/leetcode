class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        std::sort(coins.begin(), coins.end());

        int ret = 0;
        for (int i = 0, limit = 0; limit < target;) {
            if (i >= coins.size() || limit + 1 < coins[i]) {
                ++ret;
                limit += limit + 1;
            }
            else {
                limit += coins[i];
                ++i;
            }
        }

        return ret;
    }
};
