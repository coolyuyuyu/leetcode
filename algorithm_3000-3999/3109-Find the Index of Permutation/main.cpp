template<typename T, typename Alloc = std::allocator<T>>
class BinaryIndexedTree {
public:
    explicit BinaryIndexedTree(std::size_t size)
        : m_size(size)
        , m_nums(m_size + 1)
        , m_sums(m_size + 1) {
    }

    template<typename InputIterator>
    explicit BinaryIndexedTree(InputIterator first, InputIterator last)
        : m_size(std::distance(first, last))
        , m_nums(m_size + 1)
        , m_sums(m_size + 1) {
        std::size_t n = size();
        for (std::size_t i = 0; first != last; ++i, ++first) {
            set(i, first);
        }
    }

    inline std::size_t size() const {
        return m_size;
    }

    inline void set(std::size_t i, T val) {
        setByIdx(i + 1, val);
    }

    inline T get(std::size_t i) const {
        return getByIdx(i + 1);
    }

    inline T sum(std::size_t i) const {
       return sumByIdx(i + 1);
    }

    inline T sum(std::size_t lo, std::size_t hi) const {
        return sumByIdx(hi + 1) - sumByIdx(lo);
    }

private:
    void setByIdx(std::size_t i, T val) {
        assert(0 < i && i <= size());

        T diff = val - m_nums[i];
        m_nums[i] = val;

        std::size_t n = size();
        for (; i <= n; i += lowbit(i)) {
            m_sums[i] += diff;
        }
    }

    T getByIdx(std::size_t i) const {
        assert(0 < i && i <= size());

        return m_nums[i];
    }

    T sumByIdx(std::size_t i) const {
        T ret = 0;
        for (; i; i -= lowbit(i)) {
            ret += m_sums[i];
        }

        return ret;
    }

    inline std::size_t lowbit(std::size_t i) const {
        return i & ~(i - 1);
    }

    std::size_t m_size;
    std::vector<T, Alloc> m_nums;
    std::vector<T, Alloc> m_sums;
};

class Solution {
public:
    int M = 1e9 + 7;

    int getPermutationIndex(vector<int>& perm) {
        int n = perm.size();

        // f[i]: permutation of i elements
        int f[n];
        f[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = (1L * f[i - 1] * i) % M;
        }

        BinaryIndexedTree<int> bit(n + 1);
        for (int i = 1; i <= n; ++i) {
            bit.set(i, 1);
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = (ret + (1L * bit.sum(1, perm[i] - 1) * f[n - i - 1]) % M) % M;
            bit.set(perm[i], 0);
        }

        return ret;
    }
};
