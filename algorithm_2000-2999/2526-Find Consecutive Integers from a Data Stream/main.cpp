class DataStream {
public:
    DataStream(int value, int k)
        : m_val(value)
        , m_k(k)
        , m_invalid(k)
        , m_count(0) {
    }

    bool consec(int num) {
        ++m_count;

        if (num == m_val) {
            ++m_invalid;
        }
        else {
            m_invalid = 0;
        }

        if (!full()) {
            return false;
        }
        else {
            return m_invalid >= m_k;
        }
    }

private:
    bool full() const {
        return m_count >= m_k;
    }

    int m_val;
    int m_k;

    int m_invalid;
    int m_count;
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
