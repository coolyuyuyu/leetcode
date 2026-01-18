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
    int bySegmentTree(vector<int>& costs, vector<int>& capacity, int budget) {
        int maxCost = 0;
        for (int cost : costs) {
            if (cost < budget) {
                maxCost = std::max(maxCost, cost);
            }
        }
        auto op = [](int cap1, int cap2) {
            return std::max<int>(cap1, cap2);
        };
        SegmentTree<int, decltype(op)> st(maxCost + 1, 0, op);

        int ret = 0;
        for (int i = 0; i < costs.size(); ++i) {
            int cost = costs[i], cap = capacity[i];
            if (cost < budget) {
                ret = std::max(ret, cap + st.query(0, std::min<int>(budget - cost - 1, st.size() - 1)));
                st.set(cost, std::max(st.get(cost), cap));
            }
        }

        return ret;
    }

    int byBinarySearch(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<pair<int, int>> machines;
        for (int i = 0; i < costs.size(); ++i) {
            int cost = costs[i], cap = capacity[i];
            if (cost >= budget) { continue; }
            machines.emplace_back(cost, cap);
        }
        std::sort(machines.begin(), machines.end());

        int n = machines.size();

        vector<int> capPreMax(n);
        for (int i = 0; i < n; ++i) {
            capPreMax[i] = (i == 0 ? machines[0].second : std::max(capPreMax[i - 1], machines[i].second));
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int cap1 = machines[i].second;

            int cap2 = 0;
            auto itr = std::lower_bound(machines.begin(), machines.begin() + i, make_pair(budget - machines[i].first, 0));
            if (itr != machines.begin()) {
                int j = std::distance(machines.begin(), std::prev(itr));
                cap2 = capPreMax[j];
            }

            ret = std::max(ret, cap1 + cap2);
        }

        return ret;
    }

    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        //return bySegmentTree(costs, capacity, budget);
        return byBinarySearch(costs, capacity, budget);
    }
};
