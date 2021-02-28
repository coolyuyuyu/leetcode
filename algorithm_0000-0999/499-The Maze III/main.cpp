class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        size_t rowCnt = maze.size(), colCnt = maze.empty() ? 0 : maze.front().size();
        vector<vector<size_t>> distances(rowCnt, vector<size_t>(colCnt, numeric_limits<size_t>::max()));
        State optimal({ hole[0], hole[1] }, numeric_limits<size_t>::max(), "impossible");

        auto comp = [&](const State& lft, const State& rht) {
            return optimal.getPosition().distance(rht.getPosition()) < optimal.getPosition().distance(lft.getPosition());
        };
        priority_queue<State, vector<State>, decltype(comp)> states(comp);
        states.emplace(Point(ball[0], ball[1]));
        while (!states.empty()) {
            State state = states.top();
            states.pop();

            const Point& pos = state.getPosition();
            if (optimal <= state) {
                continue;
            }
            else if (distances[pos.x][pos.y] < state.getDistance()) {
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
                while (0 < posTmp.y && maze[posTmp.x][posTmp.y - 1] == 0 && posTmp != optimal.getPosition()) {
                    --(posTmp.y);
                }
                if (posTmp != pos) {
                    states.emplace(posTmp, state.getDistance() + posTmp.distance(pos), state.getDirections() + "l");
                }

                // upr
                posTmp = pos;
                while (0 < posTmp.x && maze[posTmp.x - 1][posTmp.y] == 0 && posTmp != optimal.getPosition()) {
                    --(posTmp.x);
                }
                if (posTmp != pos) {
                    states.emplace(posTmp, state.getDistance() + posTmp.distance(pos), state.getDirections() + "u");
                }

                // rht
                posTmp = pos;
                while (posTmp.y + 1 < colCnt && maze[posTmp.x][posTmp.y + 1] == 0 && posTmp != optimal.getPosition()) {
                    ++(posTmp.y);
                }
                if (posTmp != pos) {
                    states.emplace(posTmp, state.getDistance() + posTmp.distance(pos), state.getDirections() + "r");
                }

                // btm
                posTmp = pos;
                while (posTmp.x + 1 < rowCnt && maze[posTmp.x + 1][posTmp.y] == 0 && posTmp != optimal.getPosition()) {
                    ++(posTmp.x);
                }
                if (posTmp != pos) {
                    states.emplace(posTmp, state.getDistance() + posTmp.distance(pos), state.getDirections() + "d");
                }
            }
        }

        return optimal.getDirections();
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
        State(const Point& pos, size_t distance = 0, const string& directions = "")
            : m_pos(pos)
            , m_distance(distance)
            , m_directions(directions) {
        }

        bool operator<=(const State& rht) const {
            if (m_distance == rht.m_distance) {
                return m_directions <= rht.m_directions;
            }
            else {
                return m_distance <= rht.m_distance;
            }
        }

        inline const Point& getPosition() const {
            return m_pos;
        }

        inline size_t getDistance() const {
            return m_distance;
        }

        inline const string& getDirections() const {
            return m_directions;
        }

    private:
        Point m_pos;
        size_t m_distance;
        string m_directions;
    };
};