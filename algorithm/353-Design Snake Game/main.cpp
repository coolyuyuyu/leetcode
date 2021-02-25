class SnakeGame {
private:
    struct Point {
        Point(int x_, int y_)
            : x(x_)
            , y(y_) {
        }

        bool operator<(const Point& rhs) const {
            if (x == rhs.x) {
                return (y < rhs.y);
            }
            else {
                return (x < rhs.x);
            }
        }

        bool operator==(const Point& rhs) const {
            return (x == rhs.x && y == rhs.y);
        }

        bool operator!=(const Point& rhs) const {
            return !(*this == rhs);
        }

        int x;
        int y;
    };

    class Body {
    public:
        Body(int x, int y) {
            push(Point(x, y));
        }

        const Point& head() const {
            return m_pointQueue.back();
        }

        const Point& tail() const {
            return m_pointQueue.front();
        }

        void push(const Point& p) {
            m_pointQueue.push(p);
            m_pointSet.emplace(p);
        }

        void pop() {
            m_pointSet.erase(m_pointQueue.front());
            m_pointQueue.pop();
        }

        bool conflict(const Point& p) const {
            return (m_pointSet.find(p) != m_pointSet.end());
        }

    private:
        queue<Point> m_pointQueue;
        set<Point> m_pointSet;
    };

public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food)
        : m_w(width)
        , m_h(height)
        , m_body(0, 0)
        , m_score(0) {
        for (const auto& f : food) {
            m_foods.emplace(f[1], f[0]);
        }
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if (m_score < 0) {
            return -1;
        }

        Point head = m_body.head();
        switch (direction[0]) {
            case 'L':
                if (head.x-- == 0) {
                    return (m_score = -1);
                }
                break;
            case 'U':
                if (head.y-- == 0) {
                    return (m_score = -1);
                }
                break;
            case 'R':
                if ((head.x++ + 1) == m_w) {
                    return (m_score = -1);
                }

                break;
            case 'D':
                if ((head.y++ + 1) == m_h) {
                    return (m_score = -1);
                }
                break;
            default:
                assert(false);
                break;
        }

        if (m_body.conflict(head) && head != m_body.tail()) {
            return (m_score = -1);
        }

        if (!m_foods.empty() && head == m_foods.front()) {
            m_foods.pop();
            ++m_score;
        }
        else {
            m_body.pop();
        }
        m_body.push(head);

        return m_score;
    }

private:
    int m_w;
    int m_h;

    Body m_body;
    int m_score;

    queue<Point> m_foods;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */