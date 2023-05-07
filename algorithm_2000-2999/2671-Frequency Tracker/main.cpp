class FrequencyTracker {
public:
    FrequencyTracker() {
    }

    void add(int number) {
        auto itr = m_freq.find(number);
        if (itr != m_freq.end()) {
            int f = itr->second;
            if (--m_cnt[f] == 0) {
                m_cnt.erase(f);
            }
        }

        ++m_freq[number];
        ++m_cnt[m_freq[number]];
    }

    void deleteOne(int number) {
        auto itr = m_freq.find(number);
        if (itr == m_freq.end()) {
            return;
        }

        int f = itr->second;
        if (--m_cnt[f] == 0) {
            m_cnt.erase(f);
        }
        if (--m_freq[number] == 0) {
            m_freq.erase(number);
        }

        if (1 < f) {
            ++m_cnt[f - 1];
        }
    }

    bool hasFrequency(int frequency) {
        auto itr = m_cnt.find(frequency);
        return itr != m_cnt.end();
    }

private:
    unordered_map<int, int> m_freq; // <num, freq>
    unordered_map<int, int> m_cnt; // <freq, cnt>
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
