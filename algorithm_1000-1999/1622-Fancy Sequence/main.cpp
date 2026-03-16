int M = 1e9 + 7;

int quickPow(int base, int exp) {
    int ret = 1;
    for (; exp; exp >>= 1) {
        if (exp & 1) {
            ret = (1L * ret * base) % M;
        }
        base = (1L * base * base) % M;
    }

    return ret;
}

int inv(int num) {
    return quickPow(num, M - 2);
}

class Fancy {
public:
    Fancy()
        : m_add(0)
        , m_mul(1) {
    }

    void append(int val) {
        // append x = (val - m_add) / m_mul;

        val = ((val - m_add) % M + M) % M;
        val = (1LL * val * inv(m_mul)) % M;
        m_vals.push_back(val);
    }

    void addAll(int inc) {
        m_add += inc;
        m_add %= M;
    }

    void multAll(int m) {
        m_mul = (1LL * m_mul * m) % M;
        m_add = (1LL * m_add * m) % M;
    }

    int getIndex(int idx) {
        if (idx >= m_vals.size()) { return -1; }
        int ret = m_vals[idx];
        ret = (1LL * ret * m_mul) % M;
        ret = (ret + m_add) % M;
        return ret;
    }

private:
    vector<int> m_vals;
    int m_add;
    int m_mul;
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
