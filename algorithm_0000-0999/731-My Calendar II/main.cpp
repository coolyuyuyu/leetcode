class MyCalendarTwo {
public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        vector<pair<int, int>> ranges;
        for (const auto& [s, e] : m_events) {
            if (!(e <= start || end <= s)) {
                ranges.emplace_back(s, e);
            }
        }
        for (int i = 1; i < ranges.size(); ++i) {
            if (ranges[i - 1].second > ranges[i].first) {
                return false;
            }
        }
        m_events.emplace(start, end);

        return true;
    }

private:
    multimap<int, int> m_events;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
