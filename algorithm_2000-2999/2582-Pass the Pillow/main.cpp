class Solution {
public:
    int passThePillow(int n, int time) {
        int index = 1;
        int diff = 1;
        for (int t = 0; t < time; ++t) {
            if (n < index + diff) {
                diff = -1;
            }
            else if (index + diff == 0) {
                diff = 1;
            }
            index += diff;
        }

        return index;
    }
};
