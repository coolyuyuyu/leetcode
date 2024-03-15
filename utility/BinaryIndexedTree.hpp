#include <cassert>
#include <vector>

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

    void set(std::size_t i, T val) {
        setByIdx(i + 1, val);
    }

    T get(std::size_t i) const {
        return getByIdx(i + 1);
    }

    T sum(std::size_t i) const {
       return sumByIdx(i + 1);
    }

    T sum(std::size_t lo, std::size_t hi) const {
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

class BinaryIndexedTree2D {
public:
    BinaryIndexedTree2D(std::size_t rsize, std::size_t csize)
        : m_rsize(rsize)
        , m_csize(csize)
        , m_nums(m_rsize + 1, vector<int>(m_csize + 1))
        , m_sums(m_rsize + 1, vector<int>(m_csize + 1)) {
    }

    BinaryIndexedTree2D(const std::vector<vector<int>>& nums)
        : m_rsize(nums.size())
        , m_csize(nums.empty() ? 0 : nums[0].size())
        , m_nums(m_rsize + 1, vector<int>(m_csize + 1))
        , m_sums(m_rsize + 1, vector<int>(m_csize + 1)) {
        std::size_t m = rsize(), n = csize();
        for (std::size_t r = 0; r < m; ++r) {
            for (std::size_t c = 0; c < n; ++c) {
                set(r, c, nums[r][c]);
            }
        }
    }

    inline std::size_t rsize() const {
        return m_rsize;
    }

    inline std::size_t csize() const {
        return m_csize;
    }

    void set(std::size_t r, std::size_t c, int val) {
        setByIdx(r + 1, c + 1, val);
    }

    int get(std::size_t r, std::size_t c) const {
        return getByIdx(r + 1, c + 1);
    }

    int sum(std::size_t r, std::size_t c) const {
       return sumByIdx(r + 1, c + 1);
    }

    int sum(std::size_t rlo, std::size_t clo, std::size_t rhi, std::size_t chi) const {
        return sumByIdx(rhi + 1, chi + 1) - sumByIdx(rlo, chi + 1) - sumByIdx(rhi + 1, clo) + sumByIdx(rlo, clo);
    }

private:
    void setByIdx(std::size_t r, std::size_t c, int val) {
        assert(0 < r && r <= rsize() && 0 < c && c <= csize());

        int diff = val - m_nums[r][c];
        m_nums[r][c] = val;

        std::size_t m = rsize(), n = csize();
        std::size_t ctmp = c;
        for (; r <= m; r += lowbit(r)) {
            for (c = ctmp; c <= n; c += lowbit(c)) {
                m_sums[r][c] += diff;
            }
        }
    }

    int getByIdx(std::size_t r, std::size_t c) const {
        return m_nums[r][c];
    }

    int sumByIdx(std::size_t r, std::size_t c) const {
        int ret = 0;
        std::size_t ctmp = c;
        for (; r; r -= lowbit(r)) {
            for (c = ctmp; c; c -= lowbit(c)) {
                ret += m_sums[r][c];
            }
        }

        return ret;
    }

    inline std::size_t lowbit(std::size_t i) const {
        return i & ~(i - 1);
    }

    std::size_t m_rsize, m_csize;
    std::vector<std::vector<int>> m_nums;
    std::vector<std::vector<int>> m_sums;
};

#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    vector<int> nums = {10, 25, 22, 7, 34, 2, 9, 12, 16, 16};
    BinaryIndexedTree bit(nums);

    for (auto num : bit.m_sums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}