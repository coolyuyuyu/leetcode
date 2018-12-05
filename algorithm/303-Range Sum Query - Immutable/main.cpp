class NumArray {
public:
    NumArray(vector<int> nums)
        : m_sums(nums) {
        for (size_t i = 1; i < nums.size(); ++i) {
            m_sums[i] += m_sums[i - 1];
        }
    }

    int sumRange(int i, int j) {
        if (i > j) {
            swap(i, j);
        }

        int sum = m_sums[j];
        if (i > 0) {
            sum -= m_sums[i - 1];
        }

        return sum;
    }

private:
    vector<int> m_sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */