template<typename T>
class MaxSegmentTree {
public:
    typedef typename std::vector<T>::size_type size_type;

    explicit MaxSegmentTree(size_type n, const T& val = T()) {
        build(n, val);
    }

    void add(size_type lo, size_type hi, const T& val) {
        add(0, size() - 1, 0, lo, hi, val);
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

    template <class OutputIterator>
    OutputIterator output(OutputIterator itr) {
        output(0, size() - 1, 0, itr);
        return itr;
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
                m_tags.resize(i + 1);
            }
            m_vals[i] = val;
            m_tags[i] = false;
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
        if (m_tags[i] == false) {
            return;
        }

        m_vals[lft(i)] = m_vals[i];
        m_tags[lft(i)] = true;
        m_vals[rht(i)] = m_vals[i];
        m_tags[rht(i)] = true;
        m_tags[i] = false;
    }

    void add(size_type l, size_type h, size_type i, size_type lo, size_type hi, const T& val) {
        if (hi < l || h < lo) {
            return;
        }

        if (l == h) {
            m_vals[i] = std::max(m_vals[i], val);;
            return;
        }

        if (lo <= l && h <= hi && val >= m_vals[i]) {
            m_vals[i] = val;
            m_tags[i] = true;
            return;
        }

        pushDown(l, h, i);
        size_type m = l + (h - l) / 2;
        add(l, m, lft(i), lo, hi, val);
        add(m + 1, h, rht(i), lo, hi, val);
        m_vals[i] = std::max(m_vals[lft(i)], m_vals[rht(i)]);
    }

    template <class OutputIterator>
    void output(size_type l, size_type h, size_type i, OutputIterator& itr) {
        if (l == h || m_tags[i]) {
            *itr++ = {l, m_vals[i]};
            return;
        }

        size_type m = l + (h - l) / 2;
        output(l, m, lft(i), itr);
        output(m + 1, h, rht(i), itr);
    }

private:
    mutable std::vector<T> m_vals;
    mutable std::vector<bool> m_tags;
    size_type m_size;
};
