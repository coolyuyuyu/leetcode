class FizzBuzz {
private:
    int m_n;
    int m_index;
    mutex m_mtx;
    condition_variable m_cv;

    void run(function<void()> print, function<bool()> check) {
        while (true) {
            unique_lock<mutex> lck(m_mtx);
            while (true) {
                if (m_index > m_n) {
                    return;
                }
                else if (check()) {
                    break;
                }
                else {
                    m_cv.wait(lck);
                }
            }

            print();
            ++m_index;

            m_cv.notify_all();
        }
    }

public:
    FizzBuzz(int n)
        : m_n(n)
        , m_index(1) {
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        run(printFizz, [&](){ return (m_index % 3 == 0 && m_index % 5 != 0); });
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        run(printBuzz, [&](){ return (m_index % 3 != 0 && m_index % 5 == 0); });
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        run(printFizzBuzz, [&](){ return (m_index % 15 == 0); });
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        run([&](){ printNumber(m_index); }, [&](){ return !(m_index % 3 == 0 || m_index % 5 == 0); });
    }
};