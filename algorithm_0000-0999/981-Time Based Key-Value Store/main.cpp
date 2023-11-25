class TimeMap {
public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        m_data[key].emplace_hint(m_data[key].end(), timestamp, value);
    }

    string get(string key, int timestamp) {
        auto itr1 = m_data.find(key);
        if (itr1 == m_data.end()) {
            return "";
        }

        auto itr2 = itr1->second.upper_bound(timestamp);
        if (itr2 == itr1->second.begin()) {
            return "";
        }

        return std::prev(itr2)->second;
    }

private:
    unordered_map<string, map<int, string>> m_data;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
