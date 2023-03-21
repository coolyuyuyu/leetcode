class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (size_t i = 0; i < flowerbed.size();) {
            if (flowerbed[i]) {
                i += 2;
            }
            else if ((i + 1) == flowerbed.size() || flowerbed[i + 1] == 0) {
                if (--n <= 0) {
                    break;
                }
                i += 2;
            }
            else {
                i += 1;
            }
        }

        return n <= 0;
    }
};
