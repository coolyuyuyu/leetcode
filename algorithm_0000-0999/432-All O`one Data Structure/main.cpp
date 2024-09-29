class AllOne {
public:
    AllOne()
        : m_vals({0})
        , m_val2itr({{0, m_vals.begin()}}) {
    }

    void inc(string key) {
        int val = m_key2val[key];
        m_key2val[key] = val + 1;

        m_val2keys[val + 1].insert(key);
        if (val > 0) {
            m_val2keys[val].erase(key);
        }

        if (m_val2keys[val + 1].size() == 1) {
            m_val2itr[val + 1] = m_vals.insert(std::next(m_val2itr[val]), val + 1);
        }
        if (val > 0 && m_val2keys[val].empty()) {
            m_vals.erase(m_val2itr[val]);
            m_val2itr.erase(val);
        }
    }

    void dec(string key) {
        int val = m_key2val[key];
        m_key2val[key] = val - 1;

        if (val - 1 > 0) {
            m_val2keys[val - 1].insert(key);
        }
        m_val2keys[val].erase(key);

        if (m_val2keys[val - 1].size() == 1) {
            m_val2itr[val - 1] = m_vals.insert(m_val2itr[val], val - 1);
        }
        if (m_val2keys[val].empty()) {
            m_vals.erase(m_val2itr[val]);
            m_val2itr.erase(val);
        }
    }

    string getMaxKey() {
        if (m_vals.size() <= 1) {
            return "";
        }

        int val = *std::prev(m_vals.end());
        return *(m_val2keys[val].begin());
    }

    string getMinKey() {
        if (m_vals.size() <= 1) {
            return "";
        }

        int val = *std::next(m_vals.begin());
        return *(m_val2keys[val].begin());
    }

private:
    unordered_map<string, int> m_key2val;
    unordered_map<int, unordered_set<string>> m_val2keys;
    list<int> m_vals;
    unordered_map<int, list<int>::iterator> m_val2itr;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
