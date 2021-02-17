class H2O {
public:
    H2O()
        : m_hCount(0)
        , m_oCount(0) {
    }

    void hydrogen(function<void()> releaseHydrogen) {
        {
            unique_lock lock(m_mtx);
            m_cv.wait(lock, [&](){ return !(m_hCount == 2); });
            ++m_hCount;
        }

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        {
            unique_lock lock(m_mtx);
            if (m_hCount == 2 && m_oCount == 1) {
                m_hCount = 0;
                m_oCount = 0;
                m_cv.notify_all();
            }
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        {
            unique_lock lock(m_mtx);
            m_cv.wait(lock, [&](){ return !(m_oCount == 1); });
            ++m_oCount;
        }

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        {
            unique_lock lock(m_mtx);
            if (m_hCount == 2) {
                m_hCount = 0;
                m_oCount = 0;
                m_cv.notify_all();
            }
        }
    }

private:
    int m_hCount;
    int m_oCount;
    mutex m_mtx;
    condition_variable m_cv;
};