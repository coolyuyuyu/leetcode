class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> blocks;
        for (const vector<int>& obstacle : obstacles) {
            blocks.emplace(obstacle[0], obstacle[1]);
        }

        int x = 0, y = 0, d = 0;
        int ret = 0;
        for (int command : commands) {
            switch (command) {
            case -2:
                d = (d - 1 + dirs.size()) % dirs.size();
                break;
            case -1:
                d = (d + 1) % dirs.size();
                break;
            default:
                const auto& [dx, dy] = dirs[d];
                for (int i = 0; i < command; ++i) {
                    if (blocks.find({x + dx, y + dy}) != blocks.end()) {
                        break;
                    }
                    x += dx, y += dy;
                }
                ret = std::max(ret, x*x + y*y);
                break;
            }
        }

        return ret;
    }
};
