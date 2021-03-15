class Solution {
public:
    Solution()
        : m_nums({1}) {
    }

    int numTrees_Recursive(int n) {
        if (n < m_nums.size()) {
            return m_nums[n];
        }

        int num = 0;
        for (int i = 0; i < n; ++i) {
            num += (numTrees_Recursive(i) * numTrees_Recursive(n - i - 1));
        }
        if (m_nums.size() <= n) {
            m_nums.resize(n + 1, 0);
        }
        m_nums[n] = num;

        return m_nums[n];
    }

    int numTrees_Iterative(int n) {
        if (n < m_nums.size()) {
            return m_nums[n];
        }

        for (int i = m_nums.size(); i <= n; ++i) {
            int num = 0;
            for (int j = 0; j < i; ++j) {
                num += (m_nums[j] * m_nums[i - j - 1]);
            }
            m_nums.push_back(num);
        }

        return m_nums[n];
    }

    int numTrees(int n) {
        //return numTrees_Recursive(n);
        return numTrees_Iterative(n);
    }

private:
    vector<int> m_nums;
};