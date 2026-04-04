class PhoneDirectory {
public:
    PhoneDirectory(int maxNumbers)
        : m_used(maxNumbers, false) {
        for (int num = maxNumbers; 0 < num--;) {
            m_nums.push_front(num);
        }
    }

    int get() {
        if (m_nums.empty()) {
            return -1;
        }

        int ret = m_nums.front();
        m_nums.pop_front();
        m_used[ret] = true;

        return ret;
    }

    bool check(int number) {
        return !m_used[number];
    }

    void release(int number) {
        if (!check(number)) {
            m_nums.push_front(number);
            m_used[number] = false;
        }
    }

private:
    vector<bool> m_used;
    forward_list<int> m_nums;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
