class OrderedStream {
public:
    OrderedStream(int n)
        : m_ptr(0)
        , m_vals(n) {
    }

    vector<string> insert(int idKey, string value) {
        m_vals[idKey - 1] = value;

        int ptr = m_ptr;
        while (m_ptr < m_vals.size() && !(m_vals[m_ptr].empty())) {
            ++m_ptr;
        }

        return vector<string>(m_vals.begin() + ptr, m_vals.begin() + m_ptr);
    }

private:
    int m_ptr;
    vector<string> m_vals;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
