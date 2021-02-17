class Foo {
public:
    Foo()
        : m_state(0) {
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();


        ++m_state;
        m_cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(m_mtx);
        m_cv.wait(lck, [this](){ return !(m_state < 1); });
        ++m_state;

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        m_cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(m_mtx);
        m_cv.wait(lck, [this](){ return !(m_state < 2); });
        ++m_state;

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
private:
    int m_state;
    mutex m_mtx;
    condition_variable m_cv;
};