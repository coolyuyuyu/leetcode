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

    int byDivideAndConquer(const vector<int>& instructions) {
        int n = instructions.size();

        vector<int> cntLE(n, 0);
        vector<int> sorted(instructions);

        std::function<void(int, int)> f = [&](int lo, int hi) {
            if (hi <= lo) {
                return;
            }

            int mid = lo + (hi - lo) / 2;
            f(lo, mid);
            f(mid + 1, hi);

            for (int i = mid + 1; i <= hi; ++i) {
                auto itr = std::lower_bound(sorted.begin() + lo, sorted.begin() + mid + 1, instructions[i]);
                cntLE[i] += std::distance(sorted.begin() + lo, itr);
                cntLE[i] %= M;
            }

            std::inplace_merge(sorted.begin() + lo, sorted.begin() + mid + 1, sorted.begin() + hi + 1);;
        };
        f(0, n - 1);

        unordered_map<int, int> cntE;
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += std::min(cntLE[i], i - cntLE[i] - cntE[instructions[i]]);
            ret %= M;

            ++cntE[instructions[i]];
        }

        return ret;
    }

    int createSortedArray(vector<int>& instructions) {
        //return byBinaryIndexedTree(instructions);
        return byDivideAndConquer(instructions);
    }
};