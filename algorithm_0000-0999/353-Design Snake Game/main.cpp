class SnakeGame {
public:
    SnakeGame(int width, int height, vector<vector<int>>& food)
        : m_w(width)
        , m_h(height)
        , m_snake({{0, 0}})
        , m_score(0) {
        for (const auto& f : food) {
            m_foods.emplace(f[0], f[1]);
        }
    }

    int move(string direction) {
        if (m_score < 0) { return -1; }

        const auto [dr, dc] = dir2drc(direction);
        auto newHead = m_snake.back();
        newHead.first += dr, newHead.second += dc;
        if (newHead.first < 0 || newHead.first >= m_h || newHead.second < 0 || newHead.second >= m_w) {
            return (m_score = -1);
        }

        int newKey = pos2key(newHead);
        if (m_keys.find(newKey) != m_keys.end() && newHead != m_snake.front()) {
            return (m_score = -1);
        }

        if (!m_foods.empty() && newHead == m_foods.front()) {
            ++m_score;
            m_foods.pop();
        }
        else {
            m_keys.erase(pos2key(m_snake.front()));
            m_snake.pop();
        }
        m_snake.push(newHead);
        m_keys.insert(newKey);

        return m_score;
    }

private:
    static pair<int, int> dir2drc(const string& dir) {
        switch (dir[0]) {
        case 'L': return {0, -1};
        case 'U': return {-1, 0};
        case 'R': return {0, 1};
        case 'D': return {1, 0};
        default: assert(false); return {0, 0};
        }
    }

    int pos2key(const pair<int, int>& pos) {
        return pos.first * m_w + pos.second;
    }

    int m_w;
    int m_h;

    queue<pair<int, int>> m_foods;

    queue<pair<int, int>> m_snake;
    unordered_set<int> m_keys;

    int m_score;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
