class Solution {
public:

    bool isRobotBounded(string instructions) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int idx = 0;
        int x = 0, y = 0;
        for (char c : instructions) {
            switch (c) {
            case 'G':
                x += dirs[idx].first, y += dirs[idx].second;
                break;
            case 'L':
                idx = (idx + dirs.size() - 1) % dirs.size();
                break;
            case 'R':
                idx = (idx + 1) % dirs.size();
                break;
            default:
                break;
            }
        }

        return (x == 0 && y == 0) || idx != 0;
    }
};
