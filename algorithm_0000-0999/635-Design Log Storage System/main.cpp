class LogSystem {
private:
    static constexpr string_view kMinTime = "2000:01:01:00:00:00";
    static constexpr string_view kMaxTime = "2017:12:31:23:59:59";
    inline static const unordered_map<string, int> kGran2Idx = {
        {"Year", 4},
        {"Month", 7},
        {"Day", 10},
        {"Hour", 13},
        {"Minute", 16},
        {"Second", 19}
    };

public:
    LogSystem() {
    }

    void put(int id, string timestamp) {
        m_time2id.emplace(timestamp, id);
    }

    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> ret;
        int idx = kGran2Idx.find(granularity)->second;
        start = start.substr(0, idx) + string(kMinTime.substr(idx));
        end = end.substr(0, idx) + string(kMaxTime.substr(idx));
        for (auto itr = m_time2id.lower_bound(start), endItr = m_time2id.upper_bound(end); itr != endItr; ++itr) {
            ret.push_back(itr->second);
        }

        return ret;
    }

private:
    multimap<string, int> m_time2id;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
