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

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> indexes(n);
        std::iota(indexes.begin(), indexes.end(), 0);
        std::sort(indexes.begin(), indexes.end(), [&](int i1, int i2) { return nums[i1] < nums[i2]; });

        BinaryIndexedTree bit(n);
        for (int i = 0; i < n; ++i) {
            bit.set(i, 1);
        }

        long long ret = n;
        int pre = -1;
        for (int index : indexes) {
            if (pre < index) {
                ret += bit.sum(pre + 1, index - 1);
            }
            else {
                ret += bit.sum(0, index - 1);
                ret += bit.sum(pre + 1, n - 1);
            }
            bit.set(index, 0);
            pre = index;
        }

        return ret;
    }
};
