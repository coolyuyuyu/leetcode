#include <cassert>
#include <functional>
#include <iterator>
#include <stdexcept>
#include <type_traits>
#include <vector>

namespace heap {
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
    typedef typename std::vector<T>::size_type size_type;

    template<typename InputIterator>
    explicit SegmentTree(InputIterator first, InputIterator last)
        : m_op() {
        typedef typename std::is_integral<InputIterator>::type isIntegral;
        m_root = build(first, last, isIntegral());
    }

    template<typename InputIterator>
    explicit SegmentTree(InputIterator first, InputIterator last, const BinaryOperation& op)
        : m_op(op) {
        typedef typename std::is_integral<InputIterator>::type isIntegral;
        m_root = build(first, last, isIntegral());
    }

    explicit SegmentTree(std::initializer_list<T> l)
        : m_op() {
        m_root = build(l.begin(), l.end(), std::false_type());
    }

    explicit SegmentTree(std::initializer_list<T> l, const BinaryOperation& op)
        : m_op(op) {
        m_root = build(l.begin(), l.end(), std::false_type());
    }

    explicit SegmentTree(size_type n, const T& val = T())
        : m_op() {
        m_root = build(n, val, std::true_type());
    }

    explicit SegmentTree(size_type n, const T& val, const BinaryOperation& op)
        : m_op(op) {
        m_root = build(n, val, std::true_type());
    }

    const T& top() const {
        assert(!empty());

        return m_root->val;
    }

    T query(size_type lo, size_type hi) const {
        assert(lo <= hi && hi < size());

        return query(0, size() - 1, m_root, lo, hi);
    }

    void set(size_type idx, const T& val) {
        assert(idx < size());

        set(0, size() - 1, m_root, idx, val);
    }

    const T& get(size_type idx) const {
        assert(idx < size());

        size_type l = 0, h = size() - 1;
        Node* node = m_root;
        while (l < h) {
            size_type m = l + (h - l) / 2;
            if (idx <= m) {
                h = m;
                node = node->lft;
            }
            else {
                l = m + 1;
                node = node->rht;
            }
        }

        return node->val;
    }

    size_type size() const { return m_size; }
    bool empty() const { return m_size == 0; }

private:
    template<typename InputIterator>
    Node* build(InputIterator first, InputIterator last, std::false_type) {
        m_size = std::distance(first, last);
        return m_size ? build(0, m_size - 1, first) : nullptr;
    }

    template<typename InputIterator>
    Node* build(size_type l, size_type h, InputIterator& itr) {
        assert(l <= h);
        if (l == h) {
            return new Node(*itr++);
        }
        else {
            size_type m = l + (h - l) / 2;
            Node* lftChild = build(l, m, itr);
            Node* rhtChild = build(m + 1, h, itr);
            return new Node(m_op(lftChild->val, rhtChild->val), lftChild, rhtChild);
        }
    }

    Node* build(size_type n, const T& val, std::true_type) {
        m_size = n;
        return m_size ? build(0, m_size - 1, val) : nullptr;
    }

    Node* build(size_type l, size_type h, const T& val) {
        assert(l <= h);
        if (l == h) {
            return new Node(val);
        }
        else {
            size_type m = l + (h - l) / 2;
            Node* lftChild = build(l, m, val);
            Node* rhtChild = build(m + 1, h, val);
            return new Node(m_op(lftChild->val, rhtChild->val), lftChild, rhtChild);
        }
    }

    void set(size_type l, size_type h, Node* node, size_type idx, const T& val) {
        assert(l <= h);

        if (idx < l || h < idx) {
            return;
        }

        if (l == h) {
            node->val = val;
        }
        else {
            size_type m = l + (h - l) / 2;
            set(l, m, node->lft, idx, val);
            set(m + 1, h, node->rht, idx, val);
            node->val = m_op(node->lft->val, node->rht->val);
        }
    }

    T query(size_type l, size_type h, Node* node, size_type lo, size_type hi) const {
        assert(l <= h);

        if (lo <= l && h <= hi) {
            return node->val;
        }
        else {
            size_type m = l + (h - l) / 2;
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
    size_type m_size;
};
}

#include <iostream>

int main() {
    std::vector<int> nums = { 1,2,3 };
    llist::SegmentTree<int> st1(nums.begin(), nums.end());
    std::cout << st1.top() << std::endl;

    llist::SegmentTree<int> st2({4, 5, 6});
    std::cout << st2.top() << std::endl;

    int n = 5;
    int v = 10;
    llist::SegmentTree<int> st3(n, v);
    std::cout << st3.top() << std::endl;

    llist::SegmentTree<int> st4(nums.data(), nums.data() + nums.size());
    std::cout << st4.top() << std::endl;

    return 0;
}
