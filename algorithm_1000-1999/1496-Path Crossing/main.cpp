class Solution {
public:
    unordered_map<char, pair<int, int>> dirs = {{'N', {0, 1}}, {'S', {0, -1}}, {'E', {1, 0}}, {'W', {-1, 0}}};

    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        set<pair<int, int>> visited = {{x, y}};
        for (char c : path) {
            const auto& [diffX, diffY] = dirs[c];
            x += diffX, y += diffY;
            if (visited.insert({x, y}).second == false) {
                return true;
            }
        }

        return false;
    }
};
