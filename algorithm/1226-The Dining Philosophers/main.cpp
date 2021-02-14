class DiningPhilosophers {
public:
    DiningPhilosophers()
        : m_mutexs(5) {
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int index1 = philosopher;
        int index2 = (philosopher + 1) % m_mutexs.size();
        if (philosopher % 2 == 1) {
            swap(index1, index2);
        }

        unique_lock lck1(m_mutexs[index1]);
        unique_lock lck2(m_mutexs[index2]);

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }
private:
    vector<mutex> m_mutexs;
};