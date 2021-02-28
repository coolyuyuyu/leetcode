class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        m_timestamps.emplace_back(timestamp);
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        size_t lo = 0, hi = m_timestamps.size();
        int target = timestamp - 300 + 1;
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (target <= m_timestamps[mid]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return m_timestamps.size() - lo;
    }

private:
    vector<int> m_timestamps;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */