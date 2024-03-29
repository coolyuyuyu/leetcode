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
    long long byBit(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int indexes[n];
        for (int i = 0; i < n; ++i) {
            indexes[nums1[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            nums2[i] = indexes[nums2[i]];
        }

        vector<int> cntSmallerBefSelf(n);
        BinaryIndexedTree bit1(n);
        for (int i = 0; i < n; ++i) {
            cntSmallerBefSelf[i] = bit1.sum(nums2[i]);
            bit1.set(nums2[i], 1);
        }

        vector<int> cntGreaterAftSelf(n);
        BinaryIndexedTree bit2(n);
        for (int i = n; 0 < i--;) {
            cntGreaterAftSelf[i] = bit2.sum(nums2[i], n - 1);
            bit2.set(nums2[i], 1);
        }

        long long ret = 0;
        for (int i = 1; (i + 1) < n; ++i) {
            ret += (long long)cntSmallerBefSelf[i] * cntGreaterAftSelf[i];
        }

        return ret;
    }

    long long byDivideAndConquer(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int indexes[n];
        for (int i = 0; i < n; ++i) {
            indexes[nums1[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            nums2[i] = indexes[nums2[i]];
        }

        int sorted2[n];
        std::copy(nums2.begin(), nums2.end(), sorted2);

        int cntSmallerBefSelf[n];
        std::fill(cntSmallerBefSelf, cntSmallerBefSelf + n, 0);
        int cntGreaterAftSelf[n];
        std::fill(cntGreaterAftSelf, cntGreaterAftSelf + n, 0);
        std::function<void(int, int)> f = [&](int lo, int hi) {
            if (lo >= hi) { return; }

            int mid = lo + (hi - lo) / 2;
            f(lo, mid);
            f(mid + 1, hi);

            for (int i = mid + 1; i <= hi; ++i) {
                cntSmallerBefSelf[i] += std::distance(sorted2 + lo, std::lower_bound(sorted2 + lo, sorted2 + mid + 1, nums2[i]));
            }
            for (int i = lo; i <= mid; ++i) {
                cntGreaterAftSelf[i] += std::distance(std::upper_bound(sorted2 + mid + 1, sorted2 + hi + 1, nums2[i]), sorted2 + hi + 1);
            }

            std::inplace_merge(sorted2 + lo, sorted2 + mid + 1, sorted2 + hi + 1);
        };
        f(0, n - 1);

        long long ret = 0;
        for (int i = 1; i + 1 < n; ++i) {
            ret += 1LL * cntSmallerBefSelf[i] * cntGreaterAftSelf[i];
        }
        return ret;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        //return byBit(nums1, nums2);
        return byDivideAndConquer(nums1, nums2);
    }
};
