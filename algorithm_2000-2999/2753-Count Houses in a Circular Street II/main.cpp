/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 * };
 */
class Solution {
public:
    int houseCount(Street* street, int k) {
        while (!street->isDoorOpen()) {
            street->moveRight();
        }
        street->moveRight();

        int ret = 0;
        for (int i = 0; i < k; ++i) {
            if (street->isDoorOpen()) {
                street->closeDoor();
                ret = i + 1;
            }
            street->moveRight();
        }

        return ret;
    }
};
