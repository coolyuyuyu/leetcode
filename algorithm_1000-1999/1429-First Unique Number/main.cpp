class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            add(num);
        }
    }

    int showFirstUnique() {
        while (!m_uniques.empty()) {
            if (m_freq[m_uniques.front()] == 1) {
                break;
            }
            m_uniques.pop();
        }

        return m_uniques.empty() ? -1 : m_uniques.front();
    }

    void add(int value) {
        if (++m_freq[value] == 1) {
            m_uniques.push(value);
        }
    }

private:
    unordered_map<int, int> m_freq;
    queue<int> m_uniques;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
