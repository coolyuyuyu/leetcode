class AllOne {
public:
    AllOne() {
    }

    void inc(string key) {
        int& cnt = m_key2cnt[key];
        if (cnt > 0) {
            m_pairs.erase({cnt, key});
        }
        m_pairs.insert({++cnt, key});
    }

    void dec(string key) {
        int& cnt = m_key2cnt[key];
        assert(cnt > 0);
        m_pairs.erase({cnt, key});
        if (--cnt > 0) {
            m_pairs.insert({cnt, key});
        }
    }

    string getMaxKey() {
        if (m_pairs.empty()) { return ""; }
        return m_pairs.rbegin()->second;
    }

    string getMinKey() {
        if (m_pairs.empty()) { return ""; }
        return m_pairs.begin()->second;
    }

private:
    unordered_map<string, int> m_key2cnt;
    set<pair<int, string>> m_pairs;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
