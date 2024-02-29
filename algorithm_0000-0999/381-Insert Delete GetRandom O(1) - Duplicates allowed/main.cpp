class RandomizedCollection {
public:
    RandomizedCollection() {
    }

    bool insert(int val) {
        bool missing = m_val2indexes.find(val) == m_val2indexes.end();
        m_val2indexes[val].insert(m_vals.size());
        m_vals.push_back(val);
        return missing;
    }

    bool remove(int val) {
        if (m_val2indexes.find(val) == m_val2indexes.end()) {
            return false;
        }

        if (val == m_vals.back()) {
            m_vals.pop_back();
            m_val2indexes[val].erase(m_vals.size());
        }
        else {
            int index = *m_val2indexes[val].begin();
            int val2 = m_vals.back();
            int index2 = m_vals.size() - 1;
            m_vals.pop_back();
            m_vals[index] = val2;
            m_val2indexes[val2].erase(index2);
            m_val2indexes[val2].insert(index);
            m_val2indexes[val].erase(index);
        }
        if (m_val2indexes[val].empty()) {
            m_val2indexes.erase(val);
        }

        return true;
    }

    int getRandom() {
        return m_vals[std::rand() % m_vals.size()];
    }

private:
    vector<int> m_vals;
    unordered_map<int, unordered_set<int>> m_val2indexes;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
