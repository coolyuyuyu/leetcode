class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int, int>> dirs = {{'N', {0, 1}}, {'S', {0, -1}}, {'E', {1, 0}}, {'W', {-1, 0}}};
        int x = 0, y = 0;

        set<pair<int, int>> visited;
        visited.emplace(x, y);
        for (char ch : path) {
            const auto& [dx, dy] = dirs[ch];
            x += dx, y += dy;
            if (visited.emplace(x, y).second == false) {
                return true;
            }
        }

        return false;
    }
};
