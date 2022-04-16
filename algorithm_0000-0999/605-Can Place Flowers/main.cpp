class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (size_t i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 0) {
                if (i + 1 == flowerbed.size() || flowerbed[i + 1] == 0) {
                    if (--n <= 0) {
                        break;
                    }
                    ++i;
                }
            }
            else {
                ++i;
            }
        }

        return n <= 0;
    }
};
