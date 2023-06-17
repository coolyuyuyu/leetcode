class RegionSumStrategy {
public:
    virtual void update(size_t row, size_t col, int val) = 0;
    virtual int sum(size_t rowLo, size_t colLo, size_t rowHi, size_t colHi) const = 0;
};

class RegionSumPrefixSum : public RegionSumStrategy {
public:
    RegionSumPrefixSum(vector<vector<int>>& matrix)
        : m_rowSize(matrix.size())
        , m_colSize(matrix.empty() ? 0 : matrix.front().size())
        , m_numMatrix(matrix)
        , m_sumMatrix(matrix) {
        for (size_t row = 1; row < m_rowSize; ++row) {
            m_sumMatrix[row][0] += m_sumMatrix[row - 1][0];
        }
        for (size_t col = 1; col < m_colSize; ++col) {
            m_sumMatrix[0][col] += m_sumMatrix[0][col - 1];
        }

        for (size_t row = 1; row < m_rowSize; ++row) {
            for (size_t col = 1; col < m_colSize; ++ col) {
                m_sumMatrix[row][col] += (m_sumMatrix[row][col - 1] + m_sumMatrix[row - 1][col] - m_sumMatrix[row - 1][col - 1]);
            }
        }
    }

    void update(size_t row, size_t col, int val) {
        int diff = val - m_numMatrix[row][col];
        m_numMatrix[row][col] = val;

        vector<int>& sums = m_sumMatrix[row];
        for (size_t r = row; r < m_rowSize; ++r) {
            vector<int>& sums = m_sumMatrix[r];
            for (size_t c = col; c < m_colSize; ++c) {
                sums[c] += diff;
            }
        }
    }

    int sum(size_t rowLo, size_t colLo, size_t rowHi, size_t colHi) const {
        int ans = m_sumMatrix[rowHi][colHi];
        if (0 < rowLo) {
            ans -= m_sumMatrix[rowLo - 1][colHi];
            if (0 < colLo) {
                ans -= m_sumMatrix[rowHi][colLo - 1];
                ans += m_sumMatrix[rowLo - 1][colLo - 1];
            }
        }
        else {
            if (0 < colLo) {
                ans -= m_sumMatrix[rowHi][colLo - 1];
            }
        }
        return ans;
    }

private:
    size_t m_rowSize, m_colSize;
    vector<vector<int>>& m_numMatrix;
    vector<vector<int>> m_sumMatrix;
};

// RangeSumSegmentTreeByHeap is NOT true 2D. It should be updated.
class RangeSumSegmentTreeByHeap : public RegionSumStrategy {
public:
    RangeSumSegmentTreeByHeap(const vector<vector<int>>& matrix)
        : m_size(matrix.empty() ? 0 : matrix.front().size())
        , m_sumMatrix(matrix.size(), vector<int>(m_size)) {
        if (0 < m_size) {
            for (size_t i = 0; i < matrix.size(); ++ i) {
                if (0 < i) {
                    m_sumMatrix[i] = m_sumMatrix[i - 1];
                }
                build(0, m_size - 1, 0, m_sumMatrix[i], matrix[i]);
            }
        }
    }

    void update(size_t row, size_t col, int val) {
        update(0, m_size - 1, 0, m_sumMatrix[row], col, val);
    }

    int sum(size_t rowLo, size_t colLo, size_t rowHi, size_t colHi) const {
        int ans = query(0, m_size - 1, 0, m_sumMatrix[rowHi], 0 , colHi);
        if (0 < rowLo) {
            ans -= query(0, m_size - 1, 0, m_sumMatrix[rowLo - 1], 0 , colHi);
            if (0 < colLo) {
                ans -= query(0, m_size - 1, 0, m_sumMatrix[rowHi], 0 , colLo - 1);
                ans += query(0, m_size - 1, 0, m_sumMatrix[rowLo - 1], 0 , colLo - 1);
            }
        }
        else {
            if (0 < colLo) {
                ans -= query(0, m_size - 1, 0, m_sumMatrix[rowHi], 0 , colLo - 1);
            }
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
            sums[parent] += nums[lo];
            return;
        }

        size_t mid = lo + (hi - lo) / 2;
        size_t lftChild = lftChildIndex(parent), rhtChild = rhtChildIndex(parent);
        build(lo, mid, lftChild, sums, nums);
        build(mid + 1, hi, rhtChild, sums, nums);
        sums[parent] = sums[lftChild] + sums[rhtChild];
    }

    void update(size_t lo, size_t hi, size_t parent, vector<int>& sums, size_t i, int val) {
        assert(lo <= hi);

        if (i < lo || hi < i) {
            return;
        }

        if (lo == hi) {
            assert(i == lo);
            sums[parent] = val;
        }
        else {
            size_t mid = lo + (hi - lo) / 2;
            size_t lftChild = lftChildIndex(parent), rhtChild = rhtChildIndex(parent);
            update(lo, mid, lftChild, sums, i, val);
            update(mid + 1, hi, rhtChild, sums, i, val);
            sums[parent] = sums[lftChild] + sums[rhtChild];
        }
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

class RegionSumSegmentTreeByTree : public RegionSumStrategy {
public:
    RegionSumSegmentTreeByTree(vector<vector<int>>& matrix)
        : m_numMatrix(matrix)
        , m_root(matrix.empty() ? nullptr : (matrix.front().empty() ? nullptr : buildRow(0, 0, matrix.size() - 1, matrix.front().size() - 1, matrix))) {
    }

    ~RegionSumSegmentTreeByTree() {
        queue<TreeNode*> q;
        if (m_root) {
            q.push(m_root);
        }
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->rowLft) {
                q.push(node->rowLft);
            }
            if (node->rowRht) {
                q.push(node->rowRht);
            }
            if (node->colLft) {
                q.push(node->colLft);
            }
            if (node->colRht) {
                q.push(node->colRht);
            }

            delete node;
        }
    }

    void update(size_t row, size_t col, int val) {
        int diff = val - m_numMatrix[row][col];
        m_numMatrix[row][col] = val;

        updateRow(m_root, row, col, diff);
    }

    int sum(size_t rowLo, size_t colLo, size_t rowHi, size_t colHi) const {
        return queryRow(m_root, rowLo, colLo, rowHi, colHi);
    }

private:
    class TreeNode {
    public:
        TreeNode(size_t rl, size_t cl, size_t rh, size_t ch)
            : rowLo(rl)
            , colLo(cl)
            , rowHi(rh)
            , colHi(ch)
            , sum(0)
            , rowLft(nullptr)
            , rowRht(nullptr)
            , colLft(nullptr)
            , colRht(nullptr) {
        }

        size_t rowLo, colLo, rowHi, colHi;
        int sum;

        TreeNode* rowLft;
        TreeNode* rowRht;
        TreeNode* colLft;
        TreeNode* colRht;
    };

    TreeNode* buildRow(size_t rowLo, size_t colLo, size_t rowHi, size_t colHi, const vector<vector<int>>& matrix) {
        assert(rowLo <= rowHi && colLo <= colHi);

        TreeNode* parent = new TreeNode(rowLo, colLo, rowHi, colHi);
        if (rowLo < rowHi) {
            size_t rowMid = rowLo + (rowHi - rowLo) / 2;
            parent->rowLft = buildRow(rowLo, colLo, rowMid, colHi, matrix);
            parent->rowRht = buildRow(rowMid + 1, colLo, rowHi, colHi, matrix);
            parent->sum = parent->rowLft->sum + parent->rowRht->sum;

            if (colLo < colHi) {
                size_t colMid = colLo + (colHi - colLo) / 2;
                parent->colLft = buildCol(rowLo, colLo, rowHi, colMid, matrix);
                parent->colRht = buildCol(rowLo, colMid + 1, rowHi, colHi, matrix);
            }
        }
        else {
            if (colLo < colHi) {
                size_t colMid = colLo + (colHi - colLo) / 2;
                parent->colLft = buildCol(rowLo, colLo, rowHi, colMid, matrix);
                parent->colRht = buildCol(rowLo, colMid + 1, rowHi, colHi, matrix);
                parent->sum = parent->colLft->sum + parent->colRht->sum;
            }
            else {
                for (size_t row = rowLo; row <= rowHi; ++row) {
                    parent->sum += matrix[row][colLo];
                }
            }
        }

        return parent;
    }

    TreeNode* buildCol(size_t rowLo, size_t colLo, size_t rowHi, size_t colHi, const vector<vector<int>>& matrix) {
        assert(rowLo <= rowHi && colLo <= colHi);

        TreeNode* parent = new TreeNode(rowLo, colLo, rowHi, colHi);
        if (colLo < colHi) {
            size_t colMid = colLo + (colHi - colLo) / 2;
            parent->colLft = buildCol(rowLo, colLo, rowHi, colMid, matrix);
            parent->colRht = buildCol(rowLo, colMid + 1, rowHi, colHi, matrix);
            parent->sum = parent->colLft->sum + parent->colRht->sum;
        }
        else {
            for (size_t row = rowLo; row <= rowHi; ++row) {
                parent->sum += matrix[row][colLo];
            }
        }

        return parent;
    }

    void updateRow(TreeNode* parent, size_t row, size_t col, int diff) {
        if (!parent || row < parent->rowLo || parent->rowHi < row) {
            return;
        }

        updateCol(parent, row, col, diff);
        updateRow(parent->rowLft, row, col, diff);
        updateRow(parent->rowRht, row, col, diff);
    }

    void updateCol(TreeNode* parent, size_t row, size_t col, int diff) {
        if (!parent || col < parent->colLo || parent->colHi < col) {
            return;
        }

        parent->sum += diff;
        updateCol(parent->colLft, row, col, diff);
        updateCol(parent->colRht, row, col, diff);
    }

    int queryRow(TreeNode* parent, size_t rowLo, size_t colLo, size_t rowHi, size_t colHi) const {
        if (!parent || rowHi < parent->rowLo || parent->rowHi < rowLo) {
            return 0;
        }

        if (rowLo <= parent->rowLo && parent->rowHi <= rowHi) {
            return queryCol(parent, colLo, colHi);
        }
        else {
            return queryRow(parent->rowLft, rowLo, colLo, rowHi, colHi) + queryRow(parent->rowRht, rowLo, colLo, rowHi, colHi);
        }
    }

    int queryCol(TreeNode* parent, size_t colLo, size_t colHi) const {
        if (!parent || colHi < parent->colLo || parent->colHi < colLo) {
            return 0;
        }

        if (colLo <= parent->colLo && parent->colHi <= colHi) {
            return parent->sum;
        }
        else {
            return queryCol(parent->colLft, colLo, colHi) + queryCol(parent->colRht, colLo, colHi);
        }
    }

    vector<vector<int>>& m_numMatrix;
    TreeNode* m_root;
};

class BinaryIndexedTree2D {
public:
    BinaryIndexedTree2D(const std::vector<vector<int>>& nums)
        : m_rsize(nums.size())
        , m_csize(nums.empty() ? 0 : nums[0].size())
        , m_nums(m_rsize + 1, vector<int>(m_csize + 1))
        , m_sums(m_rsize + 1, vector<int>(m_csize + 1)) {
        std::size_t m = rsize(), n = csize();
        for (std::size_t r = 0; r < m; ++r) {
            for (std::size_t c = 0; c < n; ++c) {
                set(r, c, nums[r][c]);
            }
        }
    }

    inline std::size_t rsize() const {
        return m_rsize;
    }

    inline std::size_t csize() const {
        return m_csize;
    }

    void set(std::size_t r, std::size_t c, int val) {
        setByIdx(r + 1, c + 1, val);
    }

    int get(std::size_t r, std::size_t c) const {
        return getByIdx(r + 1, c + 1);
    }

    int sum(std::size_t r, std::size_t c) const {
       return sumByIdx(r + 1, c + 1);
    }

    int sum(std::size_t rlo, std::size_t clo, std::size_t rhi, std::size_t chi) const {
        return sumByIdx(rhi + 1, chi + 1) - sumByIdx(rlo, chi + 1) - sumByIdx(rhi + 1, clo) + sumByIdx(rlo, clo);
    }

private:
    void setByIdx(std::size_t r, std::size_t c, int val) {
        assert(0 < r && r <= rsize() && 0 < c && c <= csize());

        int diff = val - m_nums[r][c];
        m_nums[r][c] = val;

        std::size_t m = rsize(), n = csize();
        std::size_t ctmp = c;
        for (; r <= m; r += lowbit(r)) {
            for (c = ctmp; c <= n; c += lowbit(c)) {
                m_sums[r][c] += diff;
            }
        }
    }

    int getByIdx(std::size_t r, std::size_t c) const {
        return m_nums[r][c];
    }

    int sumByIdx(std::size_t r, std::size_t c) const {
        int ret = 0;
        std::size_t ctmp = c;
        for (; r; r -= lowbit(r)) {
            for (c = ctmp; c; c -= lowbit(c)) {
                ret += m_sums[r][c];
            }
        }

        return ret;
    }

    inline std::size_t lowbit(std::size_t i) const {
        return i & ~(i - 1);
    }

    std::size_t m_rsize, m_csize;
    std::vector<std::vector<int>> m_nums;
    std::vector<std::vector<int>> m_sums;
};

class RegionSumBinaryIndexTree : public BinaryIndexedTree2D, public RegionSumStrategy {
public:
    RegionSumBinaryIndexTree(vector<vector<int>>& matrix)
        : BinaryIndexedTree2D(matrix) {
    }

    void update(size_t row, size_t col, int val) {
        BinaryIndexedTree2D::set(row, col, val);
    }

    int sum(size_t rlo, size_t clo, size_t rhi, size_t chi) const {
        return BinaryIndexedTree2D::sum(rlo, clo, rhi, chi);
    }
};

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix)
        : m_numMatrix(matrix) {
        //m_strategy = new RegionSumPrefixSum(m_numMatrix);
        //m_strategy = new RangeSumSegmentTreeByHeap(m_numMatrix); // wrong, should be updated.
        //m_strategy = new RegionSumSegmentTreeByTree(m_numMatrix);
        m_strategy = new RegionSumBinaryIndexTree(m_numMatrix);
    }

    void update(size_t row, size_t col, int val) {
        return m_strategy->update(row, col, val);
    }

    int sumRegion(size_t rowLo, size_t colLo, size_t rowHi, size_t colHi) const {
        assert(rowLo <= rowHi && colLo <= colHi);
        return m_strategy->sum(rowLo, colLo, rowHi, colHi);
    }

private:
    RegionSumStrategy* m_strategy;

    vector<vector<int>> m_numMatrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
