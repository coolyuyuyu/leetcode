class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        unordered_map<string, pair<int, int>> dirs = {
            {"UP", {-1, 0}},
            {"RIGHT", {0, 1}},
            {"DOWN", {1, 0}},
            {"LEFT", {0, -1}},
        };

        int r = 0, c = 0;
        for (const string& command : commands) {
            const auto& [dr, dc] = dirs[command];
            r += dr, c += dc;
        }

        return r * n + c;
    }
};
