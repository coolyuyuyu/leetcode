class RandomizedSet {
public:
    RandomizedSet() {}

    bool insert(int val) {
        auto [_, inserted] = m_indexes.emplace(val, m_indexes.size());
        if (inserted) {
            m_vals.push_back(val);
        }

        return inserted;
    }

    bool remove(int val) {
        auto itr = m_indexes.find(val);
        if (itr == m_indexes.end()) {
            return false;
        }

        m_vals[itr->second] = m_vals.back();
        m_indexes[m_vals.back()] = itr->second;
        m_vals.pop_back();
        m_indexes.erase(itr);
        return true;
    }

    int getRandom() {
        return m_vals[rand() % m_vals.size()];
    }

private:
    unordered_map<int, int> m_indexes;
    vector<int> m_vals;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
