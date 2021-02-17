class FooBar {
private:
    int m_n;
    mutex m_mtx1;
    mutex m_mtx2;

public:
    FooBar(int n):
        m_n(n) {
        m_mtx2.lock();
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < m_n; i++) {
            m_mtx1.lock();

            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();

            m_mtx2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < m_n; i++) {
            m_mtx2.lock();

            // printBar() outputs "bar". Do not change or remove this line.
            printBar();

            m_mtx1.unlock();
        }
    }
};