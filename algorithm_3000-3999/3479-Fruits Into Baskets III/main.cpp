template<typename T>
class MaxSegmentTree {
public:
    typedef typename std::vector<T>::size_type size_type;

    template<typename InputIterator>
    explicit MaxSegmentTree(InputIterator first, InputIterator last) {
        m_size = std::distance(first, last);
        if (m_size) {
            build(0, m_size - 1, 0, first);
        }
    }

    const T& top() const {
        assert(!empty());

        return m_vals[0];
    }

    T query(size_type lo, size_type hi) const {
        assert(lo <= hi && hi < size());

        return query(0, size() - 1, 0, lo, hi);
    }

    size_type queryGE(const T& target) const {
        size_type l = 0, h = size() - 1, i = 0;
        while (l < h) {
            assert(m_vals[i] >= target);
            size_type m = l + (h - l) / 2;
            if (m_vals[lft(i)] >= target) {
                h = m;
                i = lft(i);
            }
            else {
                l = m + 1;
                i = rht(i);
            }
        }

        return l;
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
            m_vals[i] = std::max(m_vals[lft(i)], m_vals[rht(i)]);
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
            m_vals[i] = std::max(m_vals[lft(i)], m_vals[rht(i)]);
        }
    }

    T query(size_type l, size_type h, size_type i, size_type lo, size_type hi) const {
        assert(l <= h);

        if (lo <= l && h <= hi) {
            return m_vals[i];
        }
        else {
            assert(!(hi < l));
            assert(!(h < lo));
            size_type m = l + (h - l) / 2;
            if (m < lo) {
                return query(m + 1, h, rht(i), lo, hi);
            }
            else if (hi <= m) {
                return query(l, m, lft(i), lo, hi);
            }
            else {
                return std::max(query(l, m, lft(i), lo, hi), query(m + 1, h, rht(i), lo, hi));
            }
        }
    }

    std::vector<T> m_vals;
    size_type m_size;
};

class Solution {
public:
    int bySegmentTree(vector<int>& fruits, vector<int>& baskets) {
        baskets.push_back(INT_MAX);
        MaxSegmentTree<int> mst(baskets.begin(), baskets.end());

        int ret = 0;
        for (int fruit : fruits) {
            int i = mst.queryGE(fruit);
            if (i + 1 == mst.size()) {
                ++ret;
            }
            else {
                mst.set(i, 0);
            }
        }

        return ret;
    }

    int bySquareDecomposition(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int bucketSize = std::sqrt(n);
        int bucketCnt = (n + bucketSize - 1) / bucketSize;

        vector<int> mxVals(bucketCnt, 0);
        for (int i = 0; i < n; ++i) {
            mxVals[i / bucketSize] = std::max(mxVals[i / bucketSize], baskets[i]);
        }

        int ret = 0;
        for (int fruit : fruits) {
            auto itr = std::find_if(mxVals.begin(), mxVals.end(), [&](int mxVal){ return mxVal >= fruit; });
            if (itr == mxVals.end()) {
                ++ret;
                continue;
            }

            int bucketIdx = std::distance(mxVals.begin(), itr);
            mxVals[bucketIdx] = 0;

            int bgn = bucketIdx * bucketSize;
            int end = (bucketIdx + 1 < bucketCnt) ? ((bucketIdx + 1) * bucketSize) : (n);
            for (int i = bgn, chosen = 0; i < end; ++i) {
                if (baskets[i] >= fruit && chosen == 0) {
                    baskets[i] = 0;
                    chosen = 1;
                }
                else {
                    mxVals[bucketIdx] = std::max(mxVals[bucketIdx], baskets[i]);
                }
            }
        }

        return ret;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        //return bySegmentTree(fruits, baskets);
        return bySquareDecomposition(fruits, baskets);
    }
};
