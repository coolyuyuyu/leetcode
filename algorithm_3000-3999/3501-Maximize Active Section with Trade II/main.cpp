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
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        // pos: the index of bit
        // idx: the index of segment

        int n = s.size(), m = queries.size();

        int cnt1 = 0;
        vector<tuple<char, int, int>> segs;
        vector<int> idxs(n);
        for (int pos = 0, idx = 0; pos < n; ++pos, ++idx) {
            int bgnPos = pos, endPos = pos;
            for (; endPos < n && s[bgnPos] == s[endPos]; ++endPos) {
                idxs[endPos] = idx;
            }
            --endPos;
            segs.emplace_back(s[bgnPos], bgnPos, endPos);

            if (s[bgnPos] == '1') {
                cnt1 += (endPos - bgnPos + 1);
            }
            pos = endPos;
        }

        vector<int> gains(segs.size(), 0);
        for (int idx = 1; idx + 1 < segs.size(); ++idx) {
            auto& [type, bgnPos, endPos] = segs[idx];
            if (type == '0') { continue; }

            auto& [lftType, lftBgnPos, lftEndPos] = segs[idx - 1];
            auto& [rhtType, rhtBgnPos, rhtEndPos] = segs[idx + 1];
            gains[idx] = (lftEndPos - lftBgnPos + 1) + (rhtEndPos - rhtBgnPos + 1);
        }
        auto op = [](int cap1, int cap2) {
            return std::max<int>(cap1, cap2);
        };
        SegmentTree<int, decltype(op)> st(gains.begin(), gains.end(), op);

        vector<int> ret(m, cnt1);
        for (int j = 0; j < m; ++j) {
            int lftPos = queries[j][0], rhtPos = queries[j][1];
            int lftIdx = idxs[lftPos], rhtIdx = idxs[rhtPos];
            std::function<int(int)> computeGain = [&](int idx) {
                if (idx <= lftIdx || rhtIdx <= idx) { return 0; }
                auto& [type, bgnPos, endPos] = segs[idx];
                if (type == '0') { return 0; }

                int lftGain = 0;
                auto& [lftType, lftBgnPos, lftEndPos] = segs[idx - 1];
                if (idx - 1 == lftIdx) {
                    lftGain = lftEndPos - std::max(lftBgnPos, lftPos) + 1;
                }
                else {
                    lftGain = lftEndPos - lftBgnPos + 1;
                }

                int rhtGain = 0;
                auto& [rhtType, rhtBgnPos, rhtEndPos] = segs[idx + 1];
                if (idx + 1 == rhtIdx) {
                    rhtGain = std::min(rhtEndPos, rhtPos) - rhtBgnPos + 1;
                }
                else {
                    rhtGain = rhtEndPos - rhtBgnPos + 1;
                }

                return lftGain + rhtGain;
            };

            int mxGain = std::max(computeGain(lftIdx + 1), computeGain(rhtIdx - 1));
            if (lftIdx + 2 <= rhtIdx - 2) {
                mxGain = std::max(mxGain, st.query(lftIdx + 2, rhtIdx - 2));
            }

            ret[j] += mxGain;
        }

        return ret;
    }
};
