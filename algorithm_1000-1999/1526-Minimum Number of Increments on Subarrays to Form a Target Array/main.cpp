template<typename T, typename BinaryOperation = std::plus<T>>
class SegmentTree {
public:
    typedef std::vector<T>::size_type size_type;

    template<typename InputIterator>
    explicit SegmentTree(InputIterator first, InputIterator last)
        : m_op()
        , m_size(std::distance(first, last)) {
        build(first, last);
    }

    template<typename InputIterator>
    explicit SegmentTree(InputIterator first, InputIterator last, const BinaryOperation& op)
        : m_op(op)
        , m_size(std::distance(first, last)) {
        build(first, last);
    }

    explicit SegmentTree(std::initializer_list<T> l)
        : m_op()
        , m_size(l.size()) {
        build(l.begin, l.end());
    }

    const T& top() const {
        assert(!empty());

        return m_vals[0];
    }

    T query(size_type lo, size_type hi) const {
        if (hi < lo || size() <= hi) {
            throw std::out_of_range("invalid range");
        }

        return query(0, size() - 1, 0, lo, hi);
    }

    void set(size_type idx, const T& val) {
        assert(idx < size());

        set(0, size() - 1, 0, idx, val);
    }

    const T& get(size_type idx) const {
        assert(idx < size());

        size_type l = 0, h = size() - 1, i = 0;
        while (l < h) {
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

    template<typename InputIterator>
    void build(InputIterator first, InputIterator last) {
        if (first != last) {
            build(0, m_size - 1, 0, first);
        }
    }

    template<typename InputIterator>
    void build(size_type l, size_type h, size_type i, InputIterator& itr) {
        assert(l <= h);

        if (l == h) {
            if (m_vals.size() <= i) {
                m_vals.resize(i + 1);
            }
            m_vals[i] = *itr++;
        }
        else {
            size_type m = l + (h - l) / 2;
            build(l, m, lft(i), itr);
            build(m + 1, h, rht(i), itr);
            m_vals[i] = m_op(m_vals[lft(i)], m_vals[rht(i)]);
        }
    }

    void set(size_type l, size_type h, size_type i, size_type idx, const T& val) {
        assert(l <= h);

        if (idx < l || h < idx) {
            return;
        }

        if (l == h) {
            m_vals[i] = val;
        }
        else {
            size_type m = l + (h - l) / 2;
            set(l, m, lft(i), idx, val);
            set(m + 1, h, rht(i), idx, val);
            m_vals[i] = m_op(m_vals[lft(i)], m_vals[rht(i)]);
        }
    }

    T query(size_type l, size_type h, size_type i, size_type lo, size_type hi) const {
        assert(l <= h);

        if (lo <= l && h <= hi) {
            return m_vals[i];
        }
        else {
            size_type m = l + (h - l) / 2;
            if (hi < l || m < lo) {
                return query(m + 1, h, rht(i), lo, hi);
            }
            else if (hi < m + 1 || h < lo) {
                return query(l, m, lft(i), lo, hi);
            }
            else {
                return m_op(query(l, m, lft(i), lo, hi), query(m + 1, h, rht(i), lo, hi));
            }
        }
    }

    std::vector<T> m_vals;
    BinaryOperation m_op;
    size_type m_size;
};

class Solution {
public:
    int byGreedy(vector<int>& target) {
        int ret = target[0];
        for (int i = 1; i < target.size(); ++i) {
            if (target[i - 1] < target[i]) {
                ret += target[i] - target[i - 1];
            }
        }

        return ret;
    }

    int bySegmentTree(vector<int>& target) {
        int n = target.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {target[i], i};
        }

        auto op = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return std::min(p1, p2);
        };
        SegmentTree<pair<int, int>, decltype(op)> st(pairs.begin(), pairs.end(), op);

        std::function<int(int, int, int)> dfs = [&](int lo, int hi, int base) {
            if (lo > hi) {
                return 0;
            }
            else if (lo == hi) {
                auto [val, pos] = st.get(lo);
                return val - base;
            }

            auto [val, pos] = st.query(lo, hi);
            return val - base + dfs(lo, pos - 1, val) + dfs(pos + 1, hi, val);
        };

        return dfs(0, n - 1, 0);
    }

    int minNumberOperations(vector<int>& target) {
        // return byGreedy(target);
        return bySegmentTree(target);
    }
};
