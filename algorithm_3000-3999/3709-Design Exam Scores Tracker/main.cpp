class ExamTracker {
public:
    ExamTracker()
        : m_t2sum({{0, 0}}) {
    }

    void record(int time, int score) {
        m_t2sum[time] = m_t2sum.rbegin()->second + score;
    }

    long long totalScore(int startTime, int endTime) {
        auto bgn = m_t2sum.lower_bound(startTime);
        auto end = m_t2sum.upper_bound(endTime);
        return std::prev(end)->second - std::prev(bgn)->second;
    }

private:
    map<int, long long> m_t2sum;
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
