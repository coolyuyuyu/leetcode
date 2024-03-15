#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

template <class T, class Compare = std::less<T>, class Alloc = std::allocator<std::pair<T, __gnu_pbds::null_type>>>
using ordered_set = __gnu_pbds::tree<
    T,
    __gnu_pbds::null_type,
    Compare,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update, Alloc>;

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
    vector<int> byPBDS(vector<int>& nums) {
        vector<int> arr1, arr2;
        ordered_set<pair<int, int>> oset1, oset2;

        arr1.push_back(nums[0]), oset1.insert({nums[0], 0});
        arr2.push_back(nums[1]), oset2.insert({nums[1], 1});
        for (int i = 2; i < nums.size(); ++i) {
            int gcnt1 = oset1.size() - oset1.order_of_key(make_pair(nums[i], INT_MAX));
            int gcnt2 = oset2.size() - oset2.order_of_key(make_pair(nums[i], INT_MAX));
            bool insert1;
            if (gcnt1 > gcnt2) {
                insert1 = true;
            }
            else if (gcnt1 < gcnt2) {
                insert1 = false;
            }
            else if (gcnt1 == gcnt2) {
                if (arr1.size() < arr2.size()) {
                    insert1 = true;
                }
                else if (arr1.size() == arr2.size()) {
                    insert1 = true;
                }
                else {
                    insert1 = false;
                }
            }
            if (insert1) {
                arr1.push_back(nums[i]);
                oset1.insert({nums[i], i});
            }
            else {
                arr2.push_back(nums[i]);
                oset2.insert({nums[i], i});
            }
        }

        vector<int> ret;
        ret.insert(ret.end(), arr1.begin(), arr1.end());
        ret.insert(ret.end(), arr2.begin(), arr2.end());

        return ret;
    }

    vector<int> byBIT(vector<int>& nums) {
        map<int, int> mappedNums;
        for (int num : nums) {
            mappedNums.emplace(num, 0);
        }
        int m = 0;
        for (auto& [num, mappedNum] : mappedNums) {
            mappedNum = m++;
        }

        vector<int> arr1, arr2;
        BinaryIndexedTree bit1(m), bit2(m);
        arr1.push_back(nums[0]), bit1.set(mappedNums[nums[0]], 1);
        arr2.push_back(nums[1]), bit2.set(mappedNums[nums[1]], 1);
        for (int i = 2; i < nums.size(); ++i) {
            int num = nums[i], mappedNum = mappedNums[num];
            int gcnt1 = bit1.sum(mappedNum + 1, bit1.size() - 1);
            int gcnt2 = bit2.sum(mappedNum + 1, bit2.size() - 1);;
            bool insert1;
            if (gcnt1 > gcnt2) {
                insert1 = true;
            }
            else if (gcnt1 < gcnt2) {
                insert1 = false;
            }
            else if (gcnt1 == gcnt2) {
                if (arr1.size() < arr2.size()) {
                    insert1 = true;
                }
                else if (arr1.size() == arr2.size()) {
                    insert1 = true;
                }
                else {
                    insert1 = false;
                }
            }
            if (insert1) {
                arr1.push_back(num);
                bit1.set(mappedNum, bit1.get(mappedNum) + 1);
            }
            else {
                arr2.push_back(num);
                bit2.set(mappedNum, bit2.get(mappedNum) + 1);
            }
        }

        vector<int> ret;
        ret.insert(ret.end(), arr1.begin(), arr1.end());
        ret.insert(ret.end(), arr2.begin(), arr2.end());

        return ret;
    }

    vector<int> resultArray(vector<int>& nums) {
        //return byPBDS(nums);
        return byBIT(nums);
    }
};
