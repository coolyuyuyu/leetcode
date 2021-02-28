class StringIterator {
public:
    StringIterator(string compressedString)
        : m_cstring(compressedString)
        , m_pos(0)
        , m_char(0)
        , m_count(0) {
    }

    char next(){
        if (!hasNext()) {
            return ' ';
        }
        else {
            --m_count;
            return m_char;
        }
    }

    bool hasNext() {
        if (m_count > 0) {
            return true;
        }
        else {
            if (m_cstring.size() <= m_pos) {
                return false;
            }
        }

        m_char = m_cstring[m_pos++];
        while (m_pos < m_cstring.size() && isdigit(m_cstring[m_pos])) {
            m_count *= 10;
            m_count += (m_cstring[m_pos] - '0');
            ++m_pos;
        }

        return true;
    }

private:
    string m_cstring;
    size_t m_pos;
    char m_char;
    int m_count;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */