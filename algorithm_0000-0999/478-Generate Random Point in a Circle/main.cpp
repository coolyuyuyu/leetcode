class Strategy {
public:
    virtual vector<double> randPoint() = 0;
};

class Retry : public Strategy {
public:
    Retry(double radius, double x_center, double y_center)
        : m_x(x_center)
        , m_y(y_center)
        , m_r(radius) {
    }

    vector<double> randPoint() {
        double xDiff, yDiff;
        do {
            xDiff = static_cast<double>(rand()) / RAND_MAX * 2 * m_r - m_r;
            yDiff = static_cast<double>(rand()) / RAND_MAX * 2 * m_r - m_r;
        } while (xDiff * xDiff + yDiff * yDiff >= m_r * m_r);

        return {m_x + xDiff, m_y + yDiff};
    }

private:
    double m_x, m_y;
    double m_r;
};


class NoRetry : public Strategy {
public:
    NoRetry(double radius, double x_center, double y_center)
        : m_x(x_center)
        , m_y(y_center)
        , m_r(radius) {
    }

    vector<double> randPoint() {
        double t = static_cast<double>(rand()) / RAND_MAX; // t: uniformal distribution [0, 1)
        double r = m_r * sqrt(t); // r: uniformal distribution [0, m_r^2]
        double theta = static_cast<double>(rand()) / RAND_MAX * 2 * pi;
        return {m_x + r * cos(theta), m_y + r * sin(theta)};
    }

private:
    static constexpr double pi = 3.14159;

    double m_x, m_y;
    double m_r;
};

class Solution {
public:
    Solution(double radius, double x_center, double y_center)
        //: m_strategy(new Retry(radius, x_center, y_center)) {
        : m_strategy(new NoRetry(radius, x_center, y_center)) {
    }

    vector<double> randPoint() {
        return m_strategy->randPoint();
    }

private:
    Strategy* m_strategy;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
