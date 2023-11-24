class Solution {
public:
    int maxCoins(vector<int>& piles) {
        std::sort(piles.begin(), piles.end());

        int n = piles.size() / 3;

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += piles[3 * n  - 1 - i * 2 - 1];
        }
        return ret;
    }
};
