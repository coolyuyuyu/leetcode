class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        size_t rowCnt = maze.size(), colCnt = maze.empty() ? 0 : maze.front().size();
        vector<vector<size_t>> distances(rowCnt, vector<size_t>(colCnt, numeric_limits<size_t>::max()));
        State optimal({ destination[0], destination[1] }, numeric_limits<size_t>::max());

        auto comp = [&](const State& lft, const State& rht) {
            return optimal.getPosition().distance(rht.getPosition()) < optimal.getPosition().distance(lft.getPosition());
        };
        priority_queue<State, vector<State>, decltype(comp)> states(comp);
        states.emplace(Point(start[0], start[1]));
        while (!states.empty()) {
            State state = states.top();
            states.pop();

            const Point& pos = state.getPosition();
            if (optimal <= state) {
                continue;
            }
            else if (distances[pos.x][pos.y] <= state.getDistance()) {
                continue;
            }
            else if (pos == optimal.getPosition()) {
                distances[pos.x][pos.y] = state.getDistance();
                optimal = state;
            }
            else {
                distances[pos.x][pos.y] = state.getDistance();

                Point posTmp;

                // lft
                posTmp = pos;
                while (0 < posTmp.y && maze[posTmp.x][posTmp.y - 1] == 0) {
                    --(posTmp.y);
                }
                if (posTmp != pos) {
                    State stateTmp(posTmp, state.getDistance() + posTmp.distance(pos));
                    states.push(stateTmp);
                }

                // upr
                posTmp = pos;
                while (0 < posTmp.x && maze[posTmp.x - 1][posTmp.y] == 0) {
                    --(posTmp.x);
                }
                if (posTmp != pos) {
                    State stateTmp(posTmp, state.getDistance() + posTmp.distance(pos));
                    states.push(stateTmp);
                }

                // rht
                posTmp = pos;
                while (posTmp.y + 1 < colCnt && maze[posTmp.x][posTmp.y + 1] == 0) {
                    ++(posTmp.y);
                }
                if (posTmp != pos) {
                    State stateTmp(posTmp, state.getDistance() + posTmp.distance(pos));
                    states.push(stateTmp);
                }

                // btm
                posTmp = pos;
                while (posTmp.x + 1 < rowCnt && maze[posTmp.x + 1][posTmp.y] == 0) {
                    ++(posTmp.x);
                }
                if (posTmp != pos) {
                    State stateTmp(posTmp, state.getDistance() + posTmp.distance(pos));
                    states.push(stateTmp);
                }
            }
        }

        size_t distance = optimal.getDistance();
        return distance == numeric_limits<size_t>::max() ? -1 : distance;
    }
private:
    class Point {
    public:
        Point(int x_ = 0, int y_ = 0)
            : x(x_)
            , y(y_) {
        }

        bool operator==(const Point& rht) const {
            return x == rht.x && y == rht.y;
        }

        bool operator!=(const Point& rht) const {
            return !(*this == rht);
        }

        inline size_t distance(const Point& rht) const {
            size_t d = 0;
            d += (x < rht.x ? rht.x - x : x - rht.x);
            d += (y < rht.y ? rht.y - y : y - rht.y);
            return d;
        }

        int x, y;
    };

    class State {
    public:
        State(const Point& pos, size_t distance = 0)
            : m_pos(pos)
            , m_distance(distance) {
        }

        bool operator<=(const State& rht) const {
            return m_distance <= rht.m_distance;
        }

        inline const Point& getPosition() const {
            return m_pos;
        }

        inline size_t getDistance() const {
            return m_distance;
        }

    private:
        Point m_pos;
        size_t m_distance;
    };
};