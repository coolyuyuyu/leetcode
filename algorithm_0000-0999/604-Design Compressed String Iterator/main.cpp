class StringIterator {
public:
    StringIterator(string compressedString)
        : m_str(compressedString)
        , m_itr(m_str.begin())
        , m_cnt(0)
        , m_char() {
        decompress();
    }

    char next() {
        if (!hasNext()) {
            return ' ';
        }

        char c = m_char;
        if (--m_cnt == 0) {
            decompress();
        }

        return c;
    }

    bool hasNext() {
        return (0 < m_cnt);
    }
private:
    void decompress() {
        assert(m_cnt == 0);

        if (m_itr == m_str.end()) {
            return;
        }

        m_char = *m_itr++;
        while (m_itr != m_str.end() && std::isdigit(*m_itr)) {
            m_cnt *= 10;
            m_cnt += (*m_itr - '0');
            ++m_itr;
        }
    }

    string m_str;
    string::const_iterator m_itr;
    int m_cnt;
    char m_char;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
