class MyCalendarTwo {
public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        vector<pair<int, int>> ranges;
        for (const auto& x : m_events) {
            if (!(x.second <= start || end <= x.first)) {
                ranges.push_back(x);
            }
        }

        for (int i = 0; i + 1 < ranges.size(); ++i) {
            if (ranges[i].second > ranges[i + 1].first) {
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
