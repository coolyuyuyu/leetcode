#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iterator>
#include <vector>

namespace heap {
template<typename T>
class MergeSortTree {
public:
    typedef typename std::vector<T>::size_type size_type;

    template<typename InputIterator>
    explicit MergeSortTree(InputIterator first, InputIterator last) {
        build(first, last);
    }

    explicit MergeSortTree(std::initializer_list<T> l) {
        build(l.begin(), l.end());
    }

    std::vector<T> query(size_type lo, size_type hi) const {
        assert(lo <= hi && hi < size());

        return query(0, size() - 1, 0, lo, hi);
    }

    T querySum(size_type lo, size_type hi) const {
        assert(lo <= hi && hi < size());

        return querySum(0, size() - 1, 0, lo, hi);
    }

    T queryKth(size_type lo, size_type hi, size_type k) const {
        assert(lo <= hi && hi < size() && k < (hi - lo + 1));

        size_type l = 0, h = m_vals.size() - 1;
        while (l < h) {
            size_type m = l + (h - l) / 2;
            T x = m_vals[m];
            if (countLE(lo, hi, x) <= k) {
                l = m + 1;
            }
            else {
                h = m;
            }
        }
        return m_vals[l];
    }

    size_t countLE(size_type lo, size_type hi, T val) const {
        assert(lo <= hi && hi < size());

        return countLE(0, size() - 1, 0, lo, hi, val);
    }

    T accumulateLE(size_type lo, size_type hi, T val) const {
        assert(lo <= hi && hi < size());

        return accumulateLE(0, size() - 1, 0, lo, hi, val);
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

        return m_segVals[i][0];
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
            m_vals.reserve(m_size);

            build(0, m_size - 1, 0, first);

            std::sort(m_vals.begin(), m_vals.end());
            m_vals.erase(std::unique(m_vals.begin(), m_vals.end()), m_vals.end());
        }
    }

    template<typename InputIterator>
    void build(size_type l, size_type h, size_type i, InputIterator& itr) {
        assert(l <= h);

        if (l == h) {
            if (m_segVals.size() <= i) {
                m_segVals.resize(i + 1);
                m_segSums.resize(i + 1);
            }
            T val = *itr++;
            m_segVals[i] = {val};
            m_segSums[i] = {val};
            m_vals.push_back(val);
        }
        else {
            size_type m = l + (h - l) / 2;
            build(l, m, lft(i), itr);
            build(m + 1, h, rht(i), itr);

            const std::vector<T>& lftSegVals = m_segVals[lft(i)];
            const std::vector<T>& rhtSegVals = m_segVals[rht(i)];
            m_segVals[i].resize(lftSegVals.size() + rhtSegVals.size());
            std::merge(lftSegVals.begin(), lftSegVals.end(), rhtSegVals.begin(), rhtSegVals.end(), m_segVals[i].begin());
            m_segSums[i].resize(lftSegVals.size() + rhtSegVals.size());
            std::partial_sum(m_segVals[i].begin(), m_segVals[i].end(), m_segSums[i].begin());
        }
    }

    std::vector<T> query(size_type l, size_type h, size_type i, size_type lo, size_type hi) const {
        assert(l <= h);

        if (lo <= l && h <= hi) {
            return m_segVals[i];
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
                std::vector<T> lftSegVals = query(l, m, lft(i), lo, hi);
                std::vector<T> rhtSegVals = query(m + 1, h, rht(i), lo, hi);
                std::vector<T> ret(lftSegVals.size() + rhtSegVals.size());
                std::merge(lftSegVals.begin(), lftSegVals.end(), rhtSegVals.begin(), rhtSegVals.end(), ret.begin());
                return ret;
            }
        }
    }

    T querySum(size_type l, size_type h, size_type i, size_type lo, size_type hi) const {
        assert(l <= h);

        if (lo <= l && h <= hi) {
            return m_segSums[i].back();
        }
        else {
            size_type m = l + (h - l) / 2;
            assert(!(hi < l));
            assert(!(h < lo));
            if (m < lo) {
                return querySum(m + 1, h, rht(i), lo, hi);
            }
            else if (hi <= m) {
                return querySum(l, m, lft(i), lo, hi);
            }
            else {
                return querySum(l, m, lft(i), lo, hi) + querySum(m + 1, h, rht(i), lo, hi);
            }
        }
    }

    size_t countLE(size_type l, size_type h, size_type i, size_type lo, size_type hi, T val) const {
        assert(l <= h);

        if (lo <= l && h <= hi) {
            return std::distance(m_segVals[i].begin(), std::upper_bound(m_segVals[i].begin(), m_segVals[i].end(), val));
        }
        else {
            size_type m = l + (h - l) / 2;
            assert(!(hi < l));
            assert(!(h < lo));
            if (m < lo) {
                return countLE(m + 1, h, rht(i), lo, hi, val);
            }
            else if (hi <= m) {
                return countLE(l, m, lft(i), lo, hi, val);
            }
            else {
                return countLE(m + 1, h, rht(i), lo, hi, val) + countLE(l, m, lft(i), lo, hi, val);
            }
        }
    }

    T accumulateLE(size_type l, size_type h, size_type i, size_type lo, size_type hi, T val) const {
        assert(l <= h);

        if (lo <= l && h <= hi) {
            size_t idx = std::distance(m_segVals[i].begin(), std::upper_bound(m_segVals[i].begin(), m_segVals[i].end(), val));
            return idx > 0 ? m_segSums[i][idx - 1] : 0;
        }
        else {
            size_type m = l + (h - l) / 2;
            assert(!(hi < l));
            assert(!(h < lo));
            if (m < lo) {
                return accumulateLE(m + 1, h, rht(i), lo, hi, val);
            }
            else if (hi <= m) {
                return accumulateLE(l, m, lft(i), lo, hi, val);
            }
            else {
                return accumulateLE(m + 1, h, rht(i), lo, hi, val) + accumulateLE(l, m, lft(i), lo, hi, val);
            }
        }
    }

private:
    std::vector<std::vector<T>> m_segVals;
    std::vector<std::vector<T>> m_segSums;
    std::vector<T> m_vals;
    size_type m_size;
};
}

namespace llist {
}

#include <iostream>

int main() {
    return 0;
}
