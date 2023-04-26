class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; ++i) {
            m_nums.insert(i);
        }
    }

    int popSmallest() {
        auto itr = m_nums.begin();
        int num = *itr;
        m_nums.erase(itr);

        return num;
    }

    void addBack(int num) {
        m_nums.insert(num);
    }

private:
    set<int> m_nums;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
