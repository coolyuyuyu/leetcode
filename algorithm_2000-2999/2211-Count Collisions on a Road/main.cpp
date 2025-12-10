class Solution {
public:
    int countCollisions(string directions) {
        int ret = 0;
        for (int i = 0, lftBound = 0; i < directions.size(); ++i) {
            if (lftBound == 0 && (directions[i] == 'R' || directions[i] == 'S')) {
                lftBound = 1;
            }
            else if (lftBound == 1 && directions[i] == 'L') {
                ++ret;
            }
        }
        for (int i = directions.size(), rhtBound = 0; 0 < i--;) {
            if (rhtBound == 0 && (directions[i] == 'L' || directions[i] == 'S')) {
                rhtBound = 1;
            }
            else if (rhtBound == 1 && directions[i] == 'R') {
                ++ret;
            }
        }

        return ret;
    }
};
