class Strategy {
public:
    virtual void add(int number) = 0;
    virtual bool find(int value) = 0;
};

class HashStrategy : public Strategy {
public:
    void add(int number) {
        auto p = m_duplicates.emplace(number, false);
        if (!p.second) {
            p.first->second = true;
        }
    }

    bool find(int value) {
        for (auto p : m_duplicates) {
            int x = p.first;
            int y = static_cast<long>(value) - x;
            if (x == y) {
                if (p.second) {
                    return true;
                }
            }
            else {
                if (m_duplicates.find(y) != m_duplicates.end()) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    unordered_map<int, bool> m_duplicates;
};

class TwoPointersStrategy : public Strategy {
public:
    void add(int number) {
        auto itr = std::upper_bound(m_nums.begin(), m_nums.end(), number);
        m_nums.insert(itr, number);
    }

    bool find(int value) {
        if (m_nums.empty()) {
            return false;
        }

        size_t lo = 0, hi = m_nums.size() - 1;
        while (lo < hi) {
            int sum = m_nums[lo] + m_nums[hi];
            if (sum == value) {
                return true;
            }
            else if (sum < value) {
                ++lo;
            }
            else {
                --hi;
            }
        }


        return false;
    }

private:
    vector<int> m_nums;
};

class TwoSum {
public:
    TwoSum() {
        //m_pStrategy = new HashStrategy();
        m_pStrategy = new TwoPointersStrategy();
    }

    ~TwoSum() {
        delete m_pStrategy;
    }

    void add(int number) {
        m_pStrategy->add(number);
    }

    bool find(int value) {
        return m_pStrategy->find(value);;
    }

private:
    Strategy* m_pStrategy;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
 