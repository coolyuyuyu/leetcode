class Solution {
public:
    class Point {
    public:
        int x;
        int y;
        bool operator<(const Point & rhs) const{
            if (x < rhs.x) {
                return true;
            }
            else if (x == rhs.x) {
                return y < rhs.y;
            }
            else {
                return false;
            }
        }
    };

    vector<pair<int, int>> deltas = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<Point> obstacleSet;
        for (size_t i = 0; i < obstacles.size(); ++i) {
            obstacleSet.insert({obstacles[i][0], obstacles[i][1]});
        }

        Point pos = { 0, 0 };
        int direction = 0;
        int maxDist = 0;
        for (int command : commands) {
            if (command == -1) {
                direction = (direction + 1) % deltas.size();
            }
            else if (command == -2) {
                direction = (direction - 1 + deltas.size()) % deltas.size();
            }
            else {
                const pair<int, int>& delta = deltas[direction];
                for (int step = 0; step < command; ++step) {
                    Point newPos = { pos.x + delta.first, pos.y + delta.second };
                    if (obstacleSet.find(newPos) != obstacleSet.end()) {
                        break;
                    }
                    pos = newPos;
                }

                int dist = pos.x * pos.x + pos.y * pos.y;
                if (maxDist < dist) {
                    maxDist = dist;
                }
            }
        }

        return maxDist;
    }
};