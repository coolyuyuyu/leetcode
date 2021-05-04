class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates[0][0] == coordinates[1][0]) { // vertical
            int x = coordinates[0][0];
            auto pred = [&x](const vector<int>& coordinate) {
                return (coordinate[0] == x);
            };
            return all_of(coordinates.begin() + 1, coordinates.end(), pred);
        }
        else if (coordinates[0][1] == coordinates[1][1]) { // horizontal
            int y = coordinates[0][1];
            auto pred = [&y](const vector<int>& coordinate) {
                return (coordinate[1] == y);
            };
            return all_of(coordinates.begin() + 1, coordinates.end(), pred);
        }
        else {
            double slope = static_cast<double>(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
            for (size_t i = 2; i < coordinates.size(); ++i) {
                if (coordinates[i][0] == coordinates[i - 1][0]) {
                    return false;
                }

                double slopeTmp = static_cast<double>(coordinates[i][1] - coordinates[i - 1][1]) / (coordinates[i][0] - coordinates[i - 1][0]);
                if (slopeTmp != slope) {
                    return false;
                }
            };
            return true;
        }
    }
};
