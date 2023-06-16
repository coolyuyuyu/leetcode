#include <vector>

class BinaryIndexedTree {
public:
    BinaryIndexedTree(const std::vector<int>& nums)
        : m_size(nums.size())
        , m_nums(m_size + 1)
        , m_sums(m_size + 1) {
        m_nums[0] = m_sums[0] = 0;;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            set(i, nums[i]);
        }
    }

    std::size_t size() const {
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
    void setByIdx(std::size_t idx, int val) {
        int diff = val - m_nums[idx];
        m_nums[idx] = val;

        for (std::size_t n = size(); idx <= n; idx += lowbit(idx)) {
            m_sums[idx] += diff;
        }
    }

    int getByIdx(std::size_t idx) const {
        return m_nums[idx];
    }

    int sumByIdx(std::size_t idx) const {
        int ret = 0;
        for (; idx; idx -= lowbit(idx)) {
            ret += m_sums[idx];
        }

        return ret;
    }

    std::size_t lowbit(std::size_t idx) const {
        return idx & ~(idx - 1);
    }

    std::size_t m_size;
    std::vector<int> m_nums;
    std::vector<int> m_sums;
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