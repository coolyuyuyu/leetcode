class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        std::function<int(const vector<int>&, const vector<int>&)> computeDistance = [](const vector<int>& p1, const vector<int>& p2) {
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
        };

        int totalDistance = 0;
        int diffDistance = INT_MAX;
        for (const vector<int>& nut : nuts) {
            int d1 = computeDistance(tree, nut);
            int d2 = computeDistance(squirrel, nut);
            totalDistance += d1 * 2;
            diffDistance = std::min(diffDistance, -d1 + d2);
        }

        return totalDistance + diffDistance;
    }
};
