class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

        int ret = 0;
        for (int i = 0, lftBound = 0; i < n; ++i) {
            if (lftBound == 0) {
                if (directions[i] == 'R' || directions[i] == 'S') {
                    lftBound = 1;
                }
            }
            else {
                if (directions[i] == 'L') {
                    ++ret;
                }
            }
        }
        for (int i = n, rhtBound = 0; 0 < i--;) {
            if (rhtBound == 0) {
                if (directions[i] == 'L' || directions[i] == 'S') {
                    rhtBound = 1;
                }
            }
            else {
                if (directions[i] == 'R') {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
