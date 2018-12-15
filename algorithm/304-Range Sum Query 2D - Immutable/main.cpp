class RegionSumStrategy {
public:
    virtual int sum(size_t row1, size_t col1, size_t row2, size_t col2) const = 0;
};

class RegionSumMultiple1DPrefixSum : public RegionSumStrategy {
public:
    RegionSumMultiple1DPrefixSum(const vector<vector<int>>& matrix)
        : m_sums(matrix) {
        size_t rowCnt = matrix.size(), colCnt = matrix.empty() ? 0 : matrix.front().size();
        for (size_t row = 0; row < rowCnt; ++row) {
            for (size_t col = 1; col < colCnt; ++ col) {
                m_sums[row][col] += m_sums[row][col - 1];
            }
        }
    }

    int sum(size_t row1, size_t col1, size_t row2, size_t col2) const {
        int ans = 0;
        for (size_t row = row1; row <= row2; ++ row) {
            ans += m_sums[row][col2];
            if (0 < col1) {
                ans -= m_sums[row][col1 - 1];
            }
        }
        return ans;
    }

private:
    vector<vector<int>> m_sums;
};

class RegionSum2DPrefixSum : public RegionSumStrategy {
public:
    RegionSum2DPrefixSum(const vector<vector<int>>& matrix)
        : m_sums(matrix) {
        size_t rowCnt = matrix.size(), colCnt = matrix.empty() ? 0 : matrix.front().size();
        for (size_t row = 1; row < rowCnt; ++row) {
            m_sums[row][0] += m_sums[row - 1][0];
        }
        for (size_t col = 1; col < colCnt; ++col) {
            m_sums[0][col] += m_sums[0][col - 1];
        }

        for (size_t row = 1; row < rowCnt; ++row) {
            for (size_t col = 1; col < colCnt; ++ col) {
                m_sums[row][col] += (m_sums[row][col - 1] + m_sums[row - 1][col] - m_sums[row - 1][col - 1]);
            }
        }
    }

    int sum(size_t row1, size_t col1, size_t row2, size_t col2) const {
        int ans = m_sums[row2][col2];
        if (0 < row1) {
            ans -= m_sums[row1 - 1][col2];
            if (0 < col1) {
                ans += m_sums[row1 - 1][col1 - 1];
                ans -= m_sums[row2][col1 - 1];
            }
        }
        else {
            if (0 < col1) {
                ans -= m_sums[row2][col1 - 1];
            }
        }
        return ans;
    }

private:
    vector<vector<int>> m_sums;
};

class RangeSumMultiple1DSegmentTreeByHeap : public RegionSumStrategy {
public:
    RangeSumMultiple1DSegmentTreeByHeap(const vector<vector<int>>& matrix)
        : m_size(matrix.empty() ? 0 : matrix.front().size())
        , m_sumMatrix(matrix.size(), vector<int>(m_size)) {
        if (0 < m_size) {
            for (size_t i = 0; i < matrix.size(); ++ i) {
                build(0, m_size - 1, 0, m_sumMatrix[i], matrix[i]);
            }
        }
    }

    int sum(size_t row1, size_t col1, size_t row2, size_t col2) const {
        int ans = 0;
        for (size_t row = row1; row <= row2; ++ row) {
            ans += query(0, m_size - 1, 0, m_sumMatrix[row], col1 , col2);
        }
        return ans;
    }

private:
    inline size_t lftChildIndex(size_t parent) const {
        return parent * 2 + 1;
    }

    inline size_t rhtChildIndex(size_t parent) const {
        return parent * 2 + 2;
    }

    void build(size_t lo, size_t hi, size_t parent, vector<int>& sums, const vector<int>& nums) {
        assert(lo <= hi);

        if (lo == hi) {
            if (sums.size() <= parent) {
                sums.resize(parent + 1);
            }
            sums[parent] = nums[lo];
            return;
        }

        size_t mid = lo + (hi - lo) / 2;
        size_t lftChild = lftChildIndex(parent), rhtChild = rhtChildIndex(parent);
        build(lo, mid, lftChild, sums, nums);
        build(mid + 1, hi, rhtChild, sums, nums);
        sums[parent] = sums[lftChild] + sums[rhtChild];
    }

    int query(size_t lo, size_t hi, size_t parent, const vector<int>& sums, size_t i, size_t j) const {
        assert(lo <= hi);

        if (j < lo || hi < i) {
            return 0;
        }

        if (i <= lo && hi <= j) {
            return sums[parent];
        }
        else {
            size_t mid = lo + (hi - lo) / 2;
            return query(lo, mid, lftChildIndex(parent), sums, i , j) + query(mid + 1, hi, rhtChildIndex(parent), sums, i , j);
        }
    }

    size_t m_size; // per row size, column count
    vector<vector<int>> m_sumMatrix;
};

class RegionSumMultiple1DSegmentTreeByTree : public RegionSumStrategy {
public:
    RegionSumMultiple1DSegmentTreeByTree(const vector<vector<int>>& matrix)
        : m_roots(matrix.size(), nullptr) {
        size_t size = matrix.empty() ? 0 : matrix.front().size();
        if (0 < size) {
            for (size_t i = 0; i < matrix.size(); ++i) {
                m_roots[i] = build(0, size - 1, matrix[i]);
            }
        }
    }

    ~RegionSumMultiple1DSegmentTreeByTree() {
        for (TreeNode* node : m_roots) {
            stack<TreeNode*> stk;
            while (node || stk.empty()) {
                if (node) {
                    stk.push(node);
                    node = node->lft;
                }
                else {
                    node = stk.top();
                    stk.pop();

                    TreeNode* rht = node->rht;
                    delete node;

                    node = rht;
                }
            }
        }
    }

    int sum(size_t row1, size_t col1, size_t row2, size_t col2) const {
        int ans = 0;
        for (size_t row = row1; row <= row2; ++ row) {
            ans += query(m_roots[row], col1 , col2);
        }
        return ans;
    }

private:
    class TreeNode {
    public:
        TreeNode(size_t l, size_t h)
            : lo(l)
            , hi(h)
            , sum(0)
            , lft(nullptr)
            , rht(nullptr) {
        }

        size_t lo;
        size_t hi;
        int sum;

        TreeNode* lft;
        TreeNode* rht;
    };

    TreeNode* build(size_t lo, size_t hi, const vector<int>& nums) {
        assert(lo <= hi);

        TreeNode* parent = new TreeNode(lo, hi);
        if (lo == hi) {
            parent->sum = nums[lo];
        }
        else {
            size_t mid = lo + (hi - lo) / 2;
            TreeNode* lft = build(lo, mid, nums);
            TreeNode* rht = build(mid + 1, hi, nums);
            parent->sum = lft->sum + rht->sum;
            parent->lft = lft;
            parent->rht = rht;
        }

        return parent;
    }

    int query(TreeNode* parent, size_t i, size_t j) const {
        if (!parent || j < parent->lo || parent->hi < i) {
            return 0;
        }

        if (i <= parent->lo && parent->hi <= j) {
            return parent->sum;
        }
        else {
            return query(parent->lft, i , j) + query(parent->rht, i , j);
        }
    }

    vector<TreeNode*> m_roots;
};

class RegionSumMultiple1DBinaryIndexTree : public RegionSumStrategy {
public:
    RegionSumMultiple1DBinaryIndexTree(const vector<vector<int>>& matrix)
        : m_sumMatrix(matrix.size(), vector<int>(1 + (matrix.empty() ? 0 : matrix.front().size()))) {
        for (size_t i = 0; i < matrix.size(); ++i) {
            vector<int>& sums = m_sumMatrix[i];
            const vector<int>& nums = matrix[i];
            for (size_t j = 1; j < sums.size(); ++j) {
                sums[j] = nums[j - 1];
                for (size_t k = j - lowbit(j) + 1; k < j; ++k) {
                    sums[j] += nums[k - 1];
                }
            }
        }
    }

    int sum(size_t row, size_t col) const {
        ++col;
        const vector<int>& sums = m_sumMatrix[row];

        int ans = 0;
        while (col != 0) {
            ans += sums[col];
            col -= lowbit(col);
        }
        return ans;
    }

    int sum(size_t row1, size_t col1, size_t row2, size_t col2) const {

        int ans = 0;
        for (size_t row = row1; row <= row2; ++ row) {
            ans += sum(row, col2);
            if (0 < col1) {
                ans -= sum(row, col1 - 1);
            }
        }
        return ans;
    }

private:
    size_t lowbit(size_t x) const {
        return x & ~(x - 1);
    }

    vector<vector<int>> m_sumMatrix;
};

class NumMatrix {
public:
    NumMatrix(const vector<vector<int>>& matrix) {
        m_strategy = new RegionSumMultiple1DPrefixSum(matrix);

        //m_strategy = new RegionSum2DPrefixSum(matrix);

        //m_strategy = new RangeSumMultiple1DSegmentTreeByHeap(matrix);

        //m_strategy = new RegionSumMultiple1DSegmentTreeByTree(matrix);

        //m_strategy = new RegionSumMultiple1DBinaryIndexTree(matrix);
    }

    int sumRegion(size_t row1, size_t col1, size_t row2, size_t col2) const {
        assert(row1 <= row2 && col1 <= col2);
        return m_strategy->sum(row1, col1, row2, col2);
    }

private:
    RegionSumStrategy* m_strategy;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */