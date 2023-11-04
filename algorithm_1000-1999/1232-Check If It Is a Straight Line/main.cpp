class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dx = coordinates[1][0] - coordinates[0][0], dy = coordinates[1][1] - coordinates[0][1];
        for (int i = 2; i < coordinates.size(); ++i) {
            if (dx * (coordinates[i][1] - coordinates[0][1]) != dy * (coordinates[i][0] - coordinates[0][0])) {
                return false;
            }
        }

        return true;
    }
};
