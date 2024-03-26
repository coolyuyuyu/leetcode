template<typename T>
class DiffSegmentTree {
public:
    typedef typename std::vector<T>::size_type size_type;

    explicit DiffSegmentTree(size_type n, const T& val = T()) {
        build(n, val);
    }

    void update(size_type lo, size_type hi, const T& val) {
        update(0, size() - 1, 0, lo, hi, val);
    }

    const T& get(size_type idx) const {
        assert(idx < size());

        size_type l = 0, h = size() - 1, i = 0;
        while (l < h) {
            pushDown(l, h, i);
            size_type m = l + (h - l) / 2;
            if (idx <= m) {
                h = m;
                i = lft(i);
            }
            else {
                l = m + 1;
                i = rht(i);
            }
        }

        return m_vals[i];
    }

    size_type size() const { return m_size; }
    bool empty() const { return m_size == 0; }

private:
    inline size_type lft(size_type i) const { return i * 2 + 1; }
    inline size_type rht(size_type i) const { return i * 2 + 2; }

    void build(size_type n, const T& val) {
        m_size = n;
        if (m_size) {
            build(0, m_size - 1, 0, val);
        }
    }

    void build(size_type l, size_type h, size_type i, const T& val) {
        assert(l <= h);

        if (l == h) {
            if (m_vals.size() <= i) {
                m_vals.resize(i + 1);
            }
            m_vals[i] = val;
        }
        else {
            size_type m = l + (h - l) / 2;
            build(l, m, lft(i), val);
            build(m + 1, h, rht(i), val);
        }
    }

    void pushDown(size_type l, size_type h, size_type i) const {
        if (l == h) {
            return;
        }

        m_vals[lft(i)] += m_vals[i];
        m_vals[rht(i)] += m_vals[i];
        m_vals[i] = 0;
    }

    void update(size_type l, size_type h, size_type i, size_type lo, size_type hi, const T& diff) {
        if (hi < l || h < lo) {
            return;
        }

        if (lo <= l && h <= hi) {
            m_vals[i] += diff;
        }
        else {
            pushDown(l, h, i);

            size_type m = l + (h - l) / 2;
            update(l, m, lft(i), lo, hi, diff);
            update(m + 1, h, rht(i), lo, hi, diff);
        }
    }

    mutable std::vector<T> m_vals;
    size_type m_size;
};
