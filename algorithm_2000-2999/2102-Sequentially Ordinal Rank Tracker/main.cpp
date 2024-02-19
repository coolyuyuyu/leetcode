class Strategy {
public:
    virtual void add(const string& name, int score) = 0;
    virtual string get() = 0;
};

class SetStrategy : public Strategy {
public:
    SetStrategy() {
        m_locations.insert({INT_MIN, ""});
        m_itr = m_locations.begin();
    }

    void add(const string& name, int score) {
        auto p = make_pair(-score, name);
        m_locations.insert(p);
        if (p < *m_itr) {
            m_itr = std::prev(m_itr);
        }
    }

    string get() {
        ++m_itr;
        return m_itr->second;
    }

private:
    set<pair<int, string>> m_locations;
    set<pair<int, string>>::const_iterator m_itr;
};

class HeapStrategy : public Strategy {
public:
    HeapStrategy() {
        m_pq1.push({INT_MIN, ""});
    }

    void add(const string& name, int score) {
        auto p = make_pair(-score, name);
        if (p < m_pq1.top()) {
            m_pq2.push(m_pq1.top());
            m_pq1.pop();
            m_pq1.push(p);
        }
        else {
            m_pq2.push(p);
        }
    }

    string get() {
        m_pq1.push(m_pq2.top());
        m_pq2.pop();
        return m_pq1.top().second;
    }

private:
    priority_queue<pair<int, string>, vector<pair<int, string>>, std::less<pair<int, string>>> m_pq1;
    priority_queue<pair<int, string>, vector<pair<int, string>>, std::greater<pair<int, string>>> m_pq2;
};

class SORTracker {
public:
    SORTracker() {
        // m_strategy = new SetStrategy();
        m_strategy = new HeapStrategy();
    }

    void add(string name, int score) {
        m_strategy->add(name, score);
    }

    string get() {
        return m_strategy->get();
    }

private:
    Strategy* m_strategy;
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
