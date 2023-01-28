template<typename T>
class SummaryRangesStrategy {
public:
    void addNum(int val) {
        static_cast<T*>(this)->addNum(val);
    }

    vector<vector<int>> getIntervals() const {
        return static_cast<T*>(this)->getIntervals();
    }
};

class OrderedSetStrategy : public SummaryRangesStrategy<OrderedSetStrategy> {
public:
    void addNum(int val) {
        m_vals.insert(val);
    }

    vector<vector<int>> getIntervals() const {
        vector<vector<int>> ret;

        int lft = -1, rht;
        for (int val : m_vals) {
            if (lft == -1) {
                lft = rht = val;
            }
            else if (rht + 1 == val) {
                rht = val;
            }
            else {
                ret.push_back({lft, rht});
                lft = rht = val;
            }
        }

        if (lft != -1) {
            ret.push_back({lft, rht});
        }

        return ret;
    }

private:
    set<int> m_vals;
};

class OrderedMapStrategy : public SummaryRangesStrategy<OrderedMapStrategy> {
public:
    void addNum(int val) {
        auto itr = m_intervals.upper_bound(val);
        if (itr != m_intervals.begin() && val <= std::prev(itr, 1)->second) {
            return;
        }

        itr = m_intervals.emplace(val, val).first;
        if (itr != m_intervals.begin()) {
            auto pre = std::prev(itr, 1);
            if (pre->second + 1 == val) {
                pre->second = val;
                itr = m_intervals.erase(itr);
                --itr;
            }
        }

        assert(itr != m_intervals.end());
        auto nxt = std::next(itr, 1);
        if (itr->second + 1 == nxt->first) {
            itr->second = nxt->second;
            itr = m_intervals.erase(nxt);
        }
    }

    vector<vector<int>> getIntervals() const {
        vector<vector<int>> ret;
        for (const auto& interval : m_intervals) {
            ret.push_back({interval.first, interval.second});
        }
        return ret;
    }

private:
    map<int, int> m_intervals;
};

class SummaryRanges {
public:
    SummaryRanges() {
    }

    void addNum(int val) {
        m_strategy.addNum(val);
    }

    vector<vector<int>> getIntervals() const {
        return m_strategy.getIntervals();
    }

private:
    //OrderedSetStrategy m_strategy;
    OrderedMapStrategy m_strategy;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
