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
    long long byBit(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int indexes[n];
        for (int i = 0; i < n; ++i) {
            indexes[nums1[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            nums2[i] = indexes[nums2[i]];
        }

        int cntLTBefSelf[n];
        BinaryIndexedTree<int> bit1(n);
        for (int i = 0; i < n; ++i) {
            cntLTBefSelf[i] = bit1.sum(0, nums2[i]);
            bit1.set(nums2[i], 1);
        }

        int cntGTAftSelf[n];
        BinaryIndexedTree<int> bit2(n);
        for (int i = n - 1; i >= 0; --i) {
            cntGTAftSelf[i] = bit2.sum(nums2[i], n - 1);
            bit2.set(nums2[i], 1);
        }

        long long ret = 0;
        for (int i = n - 1; i >= 0; --i) {
            ret += 1LL * cntLTBefSelf[i] * cntGTAftSelf[i];
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

        int cntLTBefSelf[n], cntGTAftSelf[n];
        std::fill(cntLTBefSelf, cntLTBefSelf + n, 0);
        std::fill(cntGTAftSelf, cntGTAftSelf + n, 0);

        std::function<void(int, int)> f = [&](int lo, int hi) {
            if (lo >= hi) { return; }

            int mid = lo + (hi - lo) / 2;
            f(lo, mid);
            f(mid + 1, hi);

            for (int i = mid + 1; i <= hi; ++i) {
                cntLTBefSelf[i] += std::distance(sorted2 + lo, std::lower_bound(sorted2 + lo, sorted2 + mid + 1, nums2[i]));
            }
            for (int i = lo; i <= mid; ++i) {
                cntGTAftSelf[i] += std::distance(std::upper_bound(sorted2 + mid + 1, sorted2 + hi + 1, nums2[i]), sorted2 + hi + 1);
            }

            std::inplace_merge(sorted2 + lo, sorted2 + mid + 1, sorted2 + hi + 1);
        };
        f(0, n - 1);

        long long ret = 0;
        for (int i = n - 1; i >= 0; --i) {
            ret += 1LL * cntLTBefSelf[i] * cntGTAftSelf[i];
        }

        return ret;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        //return byBit(nums1, nums2);
        return byDivideAndConquer(nums1, nums2);
    }
};
