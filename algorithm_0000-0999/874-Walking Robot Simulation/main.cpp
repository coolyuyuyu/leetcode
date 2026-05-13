class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        set<pair<int, int>> blocks;
        for (const auto& obstacle : obstacles) {
            int x = obstacle[0], y = obstacle[1];
            blocks.emplace(x, y);
        }

        int ret = 0;

        int curX = 0, curY = 0, d = 0;
        for (int command : commands) {
            switch (command) {
                case -2:
                    d = (d + dirs.size() - 1) % dirs.size();
                    break;
                case -1:
                    d = (d + 1) % dirs.size();
                    break;
                default:
                    for (int i = 0; i < command; ++i) {
                        const auto& [dx, dy] = dirs[d];
                        int nxtX = curX + dx, nxtY = curY + dy;
                        if (blocks.find({nxtX, nxtY}) != blocks.end()) {
                            break;
                        }
                        curX = nxtX, curY = nxtY;
                    }
                    ret = std::max(ret, curX * curX + curY * curY);
                    break;
            }
        }

        return  ret;
    }
};
