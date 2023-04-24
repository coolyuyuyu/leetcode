class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int diffX = coordinates[1][0] - coordinates[0][0], diffY = coordinates[1][1] - coordinates[0][1];
        for (size_t i = 2; i < coordinates.size(); ++i) {
            if (diffY * (coordinates[i][0] - coordinates[0][0]) != diffX * (coordinates[i][1] - coordinates[0][1])) {
                return false;
            }
        }

        return true;
    }
};
