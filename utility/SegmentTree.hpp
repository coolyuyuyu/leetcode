#include <cassert>
#include <functional>
#include <iterator>
#include <stdexcept>
#include <vector>

namespace heap {
template<typename T, typename BinaryOperation = std::plus<T>>
class SegmentTree {
public:
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

    T query(size_t lo, size_t hi) const {
        if (hi < lo || size() <= hi) {
            throw std::out_of_range("invalid range");
        }

        return query(0, size() - 1, 0, lo, hi);
    }

    void set(size_t idx, const T& val) {
        if (size() <= idx) {
            throw std::out_of_range("invalid subscript");
        }
        set(0, size() - 1, 0, idx, val);
    }

    size_t size() const { return m_size; }
    bool empty() const { return m_size == 0; }

private:
    inline size_t lft(size_t i) const { return i * 2 + 1; }
    inline size_t rht(size_t i) const { return i * 2 + 2; }

    template<typename InputIterator>
    void build(InputIterator first, InputIterator last) {
        if (first != last) {
            build(0, m_size - 1, 0, first);
        }
    }

    template<typename InputIterator>
    void build(size_t l, size_t h, size_t i, InputIterator& itr) {
        assert(l <= h);

        if (l == h) {
            if (m_vals.size() <= i) {
                m_vals.resize(i + 1);
            }
            m_vals[i] = *itr++;
        }
        else {
            size_t m = l + (h - l) / 2;
            build(l, m, lft(i), itr);
            build(m + 1, h, rht(i), itr);
            m_vals[i] = m_op(m_vals[lft(i)], m_vals[rht(i)]);
        }
    }

    void set(size_t l, size_t h, size_t i, size_t idx, const T& val) {
        assert(l <= h);

        if (idx < l || h < idx) {
            return;
        }

        if (l == h) {
            m_vals[i] = val;
        }
        else {
            size_t m = l + (h - l) / 2;
            set(l, m, lft(i), idx, val);
            set(m + 1, h, rht(i), idx, val);
            m_vals[i] = m_op(m_vals[lft(i)], m_vals[rht(i)]);
        }
    }

    T query(size_t l, size_t h, size_t i, size_t lo, size_t hi) const {
        assert(l <= h);

        if (lo <= l && h <= hi) {
            return m_vals[i];
        }
        else {
            size_t m = l + (h - l) / 2;
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
    size_t m_size;
};
}

namespace llist {
template<typename T, typename BinaryOperation = std::plus<T>>
class SegmentTree {
private:
    struct Node {
        T val;
        Node *lft, *rht;

        Node(const T& v)
            : val(v)
            , lft(nullptr)
            , rht(nullptr) {
        }

        Node(const T& v, Node* l, Node* r)
            : val(v)
            , lft(l)
            , rht(r) {
        }
    };

public:
    template<typename InputIterator>
    explicit SegmentTree(InputIterator first, InputIterator last)
        : m_op()
        , m_size(std::distance(first, last)) {
        m_root = build(first, last);
    }

    template<typename InputIterator>
    explicit SegmentTree(InputIterator first, InputIterator last, const BinaryOperation& op)
        : m_op(op)
        , m_size(std::distance(first, last)) {
        m_root = build(first, last);
    }

    explicit SegmentTree(std::initializer_list<T> l)
        : m_op()
        , m_size(l.size()) {
        m_root = build(l.begin, l.end());
    }

    T query(size_t lo, size_t hi) const {
        if (hi < lo || size() <= hi) {
            throw std::out_of_range("invalid range");
        }

        return query(0, size() - 1, m_root, lo, hi);
    }

    void set(size_t idx, const T& val) {
        if (size() <= idx) {
            throw std::out_of_range("invalid subscript");
        }
        set(0, size() - 1, m_root, idx, val);
    }

    size_t size() const { return m_size; }
    bool empty() const { return m_size == 0; }

private:
    template<typename InputIterator>
    Node* build(InputIterator first, InputIterator last) {
        return first == last ? nullptr : build(0, m_size - 1, first);
    }

    template<typename InputIterator>
    Node* build(size_t l, size_t h, InputIterator& itr) {
        assert(l <= h);
        if (l == h) {
            return new Node(*itr++);
        }
        else {
            size_t m = l + (h - l) / 2;
            Node* lftChild = build(l, m, itr);
            Node* rhtChild = build(m + 1, h, itr);
            return new Node(m_op(lftChild->val, rhtChild->val), lftChild, rhtChild);
        }
    }

    void set(size_t l, size_t h, Node* node, size_t idx, const T& val) {
        assert(l <= h);

        if (idx < l || h < idx) {
            return;
        }

        if (l == h) {
            node->val = val;
        }
        else {
            size_t m = l + (h - l) / 2;
            set(l, m, node->lft, idx, val);
            set(m + 1, h, node->rht, idx, val);
            node->val = m_op(node->lft->val, node->rht->val);
        }
    }

    T query(size_t l, size_t h, Node* node, size_t lo, size_t hi) const {
        assert(l <= h);

        if (lo <= l && h <= hi) {
            return node->val;
        }
        else {
            size_t m = l + (h - l) / 2;
            if (hi < l || m < lo) {
                return query(m + 1, h, node->rht, lo, hi);
            }
            else if (hi < m + 1 || h < lo) {
                return query(l, m, node->lft, lo, hi);
            }
            else {
                return m_op(query(l, m, node->lft, lo, hi), query(m + 1, h, node->rht, lo, hi));
            }
        }
    }

    Node* m_root;
    BinaryOperation m_op;
    size_t m_size;
};
}
