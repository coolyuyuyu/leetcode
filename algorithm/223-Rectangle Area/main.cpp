namespace chuck {
class Point {
    friend class Rectangle;
public:
    Point() {
    }

    Point(int x_, int y_)
        : x(x_)
        , y(y_) {
    }

    int x;
    int y;
};

class Rectangle {
public:
    Rectangle(const Point& ul, const Point& lr)
        : m_ul(ul)
        , m_lr(lr) {
    }

    int area() const {
        return (m_lr.x - m_ul.x) * (m_ul.y - m_lr.y);
    }

    Rectangle intersect(const Rectangle& rhs) {
        Point ul(max(m_ul.x, rhs.m_ul.x), min(m_ul.y, rhs.m_ul.y));
        Point lr(min(m_lr.x, rhs.m_lr.x), max(m_lr.y, rhs.m_lr.y));
        if (lr.x < ul.x || ul.y < lr.y) {
            ul = lr = Point(0, 0);
        }

        return Rectangle(ul, lr);
    }
private:
    Point m_ul; // upper left
    Point m_lr; // lower right
};
}

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        chuck::Rectangle rec1(chuck::Point(A, D), chuck::Point(C, B));
        chuck::Rectangle rec2(chuck::Point(E, H), chuck::Point(G, F));
        return rec1.area() + rec2.area() - rec1.intersect(rec2).area();
    }
};