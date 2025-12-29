
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
            set(i, *first);
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
    long long minInversionCount(vector<int>& nums, int k) {
        int m; { // normalize
            vector<int> vals(nums.begin(), nums.end());
            std::sort(vals.begin(), vals.end());
            vals.erase(std::unique(vals.begin(), vals.end()), vals.end());

            unordered_map<int, int> num2rank;
            for (int i = 0; i < vals.size(); ++i) {
                num2rank[vals[i]] = i;
            }
            m = num2rank.size();

            for (auto& num : nums) {
                num = num2rank[num];
            }
        }

        long long ret = LLONG_MAX;
        long long cnt = 0;
        BinaryIndexedTree<int> bit(m);
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int cur = nums[i];
            cnt += bit.sum(cur + 1, bit.size() - 1);
            bit.set(cur, bit.get(cur) + 1);

            if (i + 1 >= k) {
                ret = std::min(ret, cnt);

                int pre = nums[i + 1 - k];
                cnt -= bit.sum(0, pre - 1);
                bit.set(pre, bit.get(pre) - 1);
            }
        }

        return ret;
    }
};
