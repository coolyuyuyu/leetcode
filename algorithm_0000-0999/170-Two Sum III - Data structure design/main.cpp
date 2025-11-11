class TwoSum {
public:
    TwoSum() {
    }

    // Time: O(1)
    void add(int number) {
        auto p = m_dups.emplace(number, false);
        if (p.second == false) {
            p.first->second = true;
        }
    }

    // Time: O(n)
    bool find(int value) {
        for (const auto& [x, dup] : m_dups) {
            int y = 0LL + value - x;
            if (x == y) {
                if (dup) {
                    return true;
                }
            }
            else if (m_dups.find(y) != m_dups.end()) {
                return true;
            }
        }

        return false;;
    }

private:
    unordered_map<int, bool> m_dups;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
