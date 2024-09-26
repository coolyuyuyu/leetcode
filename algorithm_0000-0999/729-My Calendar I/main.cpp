class MyCalendar {
public:
    MyCalendar() {
    }

    bool book(int start, int end) {
        auto itr1 = m_start2end.upper_bound(start);
        if (itr1 != m_start2end.begin()) {
            auto itr2 = std::prev(itr1);
            if (itr2->second > start) {
                return false;
            }
        }
        if (itr1 != m_start2end.end()) {
            if (end > itr1->first) {
                return false;
            }
        }

        m_start2end[start] = end;
        return true;
    }

private:
    map<int, int> m_start2end;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
