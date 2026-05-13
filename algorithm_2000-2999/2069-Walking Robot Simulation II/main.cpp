class Robot {
public:
    Robot(int width, int height)
        : m_w(width), m_h(height)
        , m_x(0), m_y(0)
        , m_dir("East") {
    }

    void step(int num) {
        num %= (2 * (m_w - 1 + m_h - 1));
        if (num == 0) {
            num = (2 * (m_w - 1) + 2 * (m_h - 1));
        }

        while (num) {
            if (m_dir == "East") {
                int k = std::min(m_x + num, m_w - 1) - m_x;
                num -= k;
                m_x += k;
                if (num) {
                    m_dir = "North";
                }
            }
            else if (m_dir == "North") {
                int k = std::min(m_y + num, m_h - 1) - m_y;
                num -= k;
                m_y += k;
                if (num) {
                    m_dir = "West";
                }
            }
            else if (m_dir == "West") {
                int k = m_x - std::max(m_x - num, 0);
                num -= k;
                m_x -= k;
                if (num) {
                    m_dir = "South";
                }
            }
            else if (m_dir == "South") {
                int k = m_y - std::max(m_y - num, 0);
                num -= k;
                m_y -= k;
                if (num) {
                    m_dir = "East";
                }
            }
        }
    }

    vector<int> getPos() {
        return {m_x, m_y};
    }

    string getDir() {
        return m_dir;
    }

private:
    int m_w, m_h;
    int m_x, m_y;
    string m_dir;
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
