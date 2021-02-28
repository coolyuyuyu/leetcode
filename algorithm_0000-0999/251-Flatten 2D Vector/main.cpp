class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d)
        : m_x(0)
        , m_y(0)
        , m_vec2d(vec2d) {
    }

    int next() {
        int ret = m_vec2d[m_x][m_y];
        ++m_y;
        return ret;
    }

    bool hasNext() {
        while (m_x < m_vec2d.size()) {
            const vector<int>& vec = m_vec2d[m_x];
            if (m_y < vec.size()) {
                return true;
            }
            else {
                ++m_x;
                m_y = 0;
            }
        }

        return false;
    }

private:
    size_t m_x;
    size_t m_y;
    const vector<vector<int>>& m_vec2d;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */