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

    // TLE
    int countByLinearScan(const vector<int>& nums) {
        // counts[k]: the number of prefix of nums such that there are k mores ones than zero for each prefix
        map<int, int> counts;
        counts[0] = 1;

        int ret = 0;

        int diff = 0;
        for (int num : nums) {
            diff += (num == 1 ? 1 : -1);

            for (const auto [k, count] : counts) {
                if (diff <= k) {
                    break;
                }
                ret += count;
                ret %= M;
            }

            counts[diff] += 1;
        }

        return ret;
    }

    int countByBinaryIndexTree(const vector<int>& nums) {
        int offset = 1e5;

        BinaryIndexedTree counts(2 * offset + 1);
        counts.set(0 + offset, 1);

        int ret = 0;

        int diff = 0;
        for (int num : nums) {
            diff += (num == 1 ? 1 : -1);

            ret += counts.sum(diff + offset - 1);
            ret %= M;

            counts.set(diff + offset, counts.get(diff + offset) + 1);
        }

        return ret;
    }

    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        //return countByLinearScan(nums);
        return countByBinaryIndexTree(nums);
    }
};
