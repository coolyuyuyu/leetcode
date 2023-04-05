class MyCalendarThree {
public:
    MyCalendarThree() {
    }

    int book(int startTime, int endTime) {
        ++m_diff[startTime];
        --m_diff[endTime];

        int ret = 0;
        int sum = 0;
        for (const auto& [_, diff] : m_diff) {
            sum += diff;
            ret = std::max(ret, sum);
        }

        return ret;
    }

private:
    map<int, int> m_diff;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
