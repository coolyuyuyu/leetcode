class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n <= 0) {
            return true;
        }

        for (size_t i = 0; i < flowerbed.size(); ++i) {
            if ((i == 0 || flowerbed[i - 1] == 0)
                && flowerbed[i] == 0
                && (i + 1 >= flowerbed.size() || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                --n;

                if (n <= 0) {
                    return true;
                }
            }

        }

        return false;
    }
};