class BinaryIndexedTree {
public:
    BinaryIndexedTree(std::size_t size)
        : m_size(size)
        , m_nums(m_size + 1)
        , m_sums(m_size + 1) {
    }

    BinaryIndexedTree(const std::vector<int>& nums)
        : m_size(nums.size())
        , m_nums(m_size + 1)
        , m_sums(m_size + 1) {
        std::size_t n = size();
        for (std::size_t i = 0; i < n; ++i) {
            set(i, nums[i]);
        }
    }

    inline std::size_t size() const {
        return m_size;
    }

    void set(std::size_t i, int val) {
        setByIdx(i + 1, val);
    }

    int get(std::size_t i) const {
        return getByIdx(i + 1);
    }

    int sum(std::size_t i) const {
       return sumByIdx(i + 1);
    }

    int sum(std::size_t lo, std::size_t hi) const {
        return sumByIdx(hi + 1) - sumByIdx(lo);
    }

private:
    void setByIdx(std::size_t i, int val) {
        assert(0 < i && i <= size());

        int diff = val - m_nums[i];
        m_nums[i] = val;

        std::size_t n = size();
        for (; i <= n; i += lowbit(i)) {
            m_sums[i] += diff;
        }
    }

    int getByIdx(std::size_t i) const {
        assert(0 < i && i <= size());

        return m_nums[i];
    }

    int sumByIdx(std::size_t i) const {
        int ret = 0;
        for (; i; i -= lowbit(i)) {
            ret += m_sums[i];
        }

        return ret;
    }

    inline std::size_t lowbit(std::size_t i) const {
        return i & ~(i - 1);
    }

    std::size_t m_size;
    std::vector<int> m_nums;
    std::vector<int> m_sums;
};

template<typename T, typename BinaryOperation = std::plus<T>>
class SegmentTree {
public:
    typedef typename std::vector<T>::size_type size_type;

    template<typename InputIterator>
    explicit SegmentTree(InputIterator first, InputIterator last)
        : m_op() {
        build(first, last);
    }

    template<typename InputIterator>
    explicit SegmentTree(InputIterator first, InputIterator last, const BinaryOperation& op)
        : m_op(op) {
        build(first, last);
    }

    explicit SegmentTree(std::initializer_list<T> l)
        : m_op() {
        build(l.begin(), l.end());
    }

    explicit SegmentTree(std::initializer_list<T> l, const BinaryOperation& op)
        : m_op(op) {
        build(l.begin(), l.end());
    }

    explicit SegmentTree(size_type n, const T& val = T())
        : m_op() {
        build(n, val);
    }

    explicit SegmentTree(size_type n, const T& val, const BinaryOperation& op)
        : m_op(op) {
        build(n, val);
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
    void build(InputIterator first, InputIterator last) {
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

    void build(size_t n, const T& val) {
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
    int M = 1e9 + 7;

    int byBinaryIndexedTree(const vector<int>& instructions) {
        int n = *std::max_element(instructions.begin(), instructions.end()) + 1;
        BinaryIndexedTree bit(n);

        int ret = 0;
        for (int num : instructions) {
            ret += std::min(bit.sum(num - 1), bit.sum(num + 1, n - 1));
            ret %= M;

            bit.set(num, bit.get(num) + 1);
        }

        return ret;
    }

    int bySegmentTree(const vector<int>& instructions) {
        SegmentTree<int>::size_type maxNum = *std::max_element(instructions.begin(), instructions.end()) + 1;
        SegmentTree<int> st(maxNum + 1, 0);

        int ret = 0;
        for (int num : instructions) {
            ret += std::min(st.query(0, num - 1), st.query(num + 1, st.size() - 1));
            ret %= M;

            st.set(num, st.get(num) + 1);
        }

        return ret;
    }

    int byDivideAndConquer(const vector<int>& instructions) {
        int n = instructions.size();

        int sorted[n];
        std::copy(instructions.begin(), instructions.end(), sorted);

        int cntLT[n];
        std::fill(cntLT, cntLT + n, 0);
        std::function<void(int, int)> f = [&](int lo, int hi) {
            if (lo >= hi) { return; }

            int mid = lo + (hi - lo) / 2;
            f(lo, mid);
            f(mid + 1, hi);

            for (int i = mid + 1; i <= hi; ++i) {
                cntLT[i] += std::distance(sorted + lo, std::lower_bound(sorted + lo, sorted + mid + 1, instructions[i]));
            }

            std::inplace_merge(sorted + lo, sorted + mid + 1, sorted + hi + 1);
        };
        f(0, n - 1);

        unordered_map<int, int> cnt;
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += std::min(cntLT[i], i - cntLT[i] - cnt[instructions[i]]);
            ret %= M;

            ++cnt[instructions[i]];
        }

        return ret;
    }

    int createSortedArray(vector<int>& instructions) {
        //return byBinaryIndexedTree(instructions);
        return bySegmentTree(instructions);
        return byDivideAndConquer(instructions);
    }
};
