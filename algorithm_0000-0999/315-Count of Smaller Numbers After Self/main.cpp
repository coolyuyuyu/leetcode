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
    vector<int> byBinaryIndexedTree(const vector<int>& nums) {
        int n = nums.size();
        int offset = 1e4 + 1;

        vector<int> ret(n);
        BinaryIndexedTree bit(offset + 1e4 + 1);
        for (int i = n; 0 < i--;) {
            int num = nums[i] + offset;
            ret[i] = bit.sum(num - 1);
            bit.set(num, bit.get(num) + 1);
        }

        return ret;
    }

    vector<int> byDivideAndConquer(const vector<int>& nums) {
        vector<int> ret(nums.size(), 0);
        vector<int> sorted(nums);
        std::function<void(int, int)> f = [&](int lo, int hi) {
            if (hi <= lo) {
                return;
            }

            int mid = lo + (hi - lo) / 2;
            f(lo, mid);
            f(mid + 1, hi);

            for (int i = lo; i <= mid; ++i) {
                ret[i] += std::distance(sorted.begin() + mid + 1, std::lower_bound(sorted.begin() + mid + 1, sorted.begin() + hi + 1, nums[i]));
            }

            std::inplace_merge(sorted.begin() + lo, sorted.begin() + mid + 1, sorted.begin() + hi + 1);
        };
        f(0, nums.size() - 1);

        return ret;
    }

    vector<int> countSmaller(vector<int>& nums) {
        //return byBinaryIndexedTree(nums);
        return byDivideAndConquer(nums);
    }
};
