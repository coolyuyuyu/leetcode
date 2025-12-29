template<typename T, typename BinaryOperation = std::plus<T>>
class SegmentTree {
public:
    typedef typename std::vector<T>::size_type size_type;

    template<typename InputIterator>
    explicit SegmentTree(InputIterator first, InputIterator last)
        : m_op() {
        typedef typename std::is_integral<InputIterator>::type isIntegral;
        build(first, last, isIntegral());
    }

    template<typename InputIterator>
    explicit SegmentTree(InputIterator first, InputIterator last, const BinaryOperation& op)
        : m_op(op) {
        typedef typename std::is_integral<InputIterator>::type isIntegral;
        build(first, last, isIntegral());
    }

    explicit SegmentTree(std::initializer_list<T> l)
        : m_op() {
        build(l.begin(), l.end(), std::false_type());
    }

    explicit SegmentTree(std::initializer_list<T> l, const BinaryOperation& op)
        : m_op(op) {
        build(l.begin(), l.end(), std::false_type());
    }

    explicit SegmentTree(size_type n, const T& val = T())
        : m_op() {
        build(n, val, std::true_type());
    }

    explicit SegmentTree(size_type n, const T& val, const BinaryOperation& op)
        : m_op(op) {
        build(n, val, std::true_type());
    }

    const T& top() const {
        assert(!empty());

        return m_vals[0];
    }

    T query(size_type lo, size_type hi) const {
        assert(lo <= hi && hi < size());

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
    void build(InputIterator first, InputIterator last, std::false_type) {
        m_size = std::distance(first, last);
        if (m_size) {
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

    void build(size_type n, const T& val, std::true_type) {
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
            assert(!(hi < l));
            assert(!(h < lo));
            if (m < lo) {
                return query(m + 1, h, rht(i), lo, hi);
            }
            else if (hi <= m) {
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
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        // assume s of len k
        // for each index in [0, k - 2], the number of indexws (where s[i] != [i + 1]) + 1 is equals to the length of the longest alternating subsequence

        vector<int> nums(s.size() - 1);
        for (int i = 0; i + 1 < s.size(); ++i) {
            nums[i] = (s[i] != s[i + 1] ? 1 : 0);
        }
        SegmentTree<int> st(nums.begin(), nums.end());

        vector<int> ret;
        for (const auto& query : queries) {
            if (query[0] == 1) {
                int i = query[1];
                if (i > 0) {
                    st.set(i - 1, 1 - st.get(i - 1));
                }
                if (i < st.size()) {
                    st.set(i, 1 - st.get(i));
                }
            }
            else if (query[0] == 2) {
                int l = query[1], r = query[2];
                if (r == l) {
                    ret.push_back(0);
                }
                else {
                    ret.push_back((r - l + 1) - st.query(l, r - 1) - 1);
                }
            }
        }

        return ret;
    }
};
