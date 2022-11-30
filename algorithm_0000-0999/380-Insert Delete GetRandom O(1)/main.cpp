class RandomizedSet {
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (m_indexes.emplace(val, m_indexes.size()).second) {
            m_vals.emplace_back(val);
            return true;
        }
        else {
            return false;
        }
    }

    bool remove(int val) {
        auto itr = m_indexes.find(val);
        if (itr == m_indexes.end()) {
            return false;
        }

        m_indexes[m_vals.back()] = itr->second;
        std::swap(m_vals[itr->second], m_vals.back());
        m_vals.pop_back();
        m_indexes.erase(itr);
        return true;
    }

    int getRandom() {
        return m_vals[rand() % m_vals.size()];
    }

private:
    map<int, size_t> m_indexes;
    vector<int> m_vals;

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
