class RegionSumStrategy {
public:
    virtual int sum(size_t rowLo, size_t colLo, size_t rowHi, size_t colHi) const = 0;
};

class RegionSumMultiple1DPrefixSum : public RegionSumStrategy {
public:
    RegionSumMultiple1DPrefixSum(const vector<vector<int>>& matrix)
        : m_sumMatrix(matrix) {
        size_t rowSize = matrix.size(), colSize = matrix.empty() ? 0 : matrix.front().size();
        for (size_t row = 0; row < rowSize; ++row) {
            vector<int>& sums = m_sumMatrix[row];
            for (size_t col = 1; col < colSize; ++ col) {
                sums[col] += sums[col - 1];
            }
        }
    }

    int sum(size_t rowLo, size_t colLo, size_t rowHi, size_t colHi) const {
        int ans = 0;
        for (size_t row = rowLo; row <= rowHi; ++ row) {
            ans += m_sumMatrix[row][colHi];
        }
        if (0 < colLo) {
            for (size_t row = rowLo; row <= rowHi; ++ row) {
                ans -= m_sumMatrix[row][colLo - 1];
            }
        }
        return ans;
    }

private:
    vector<vector<int>> m_sumMatrix;
};

class RegionSum2DPrefixSum : public RegionSumStrategy {
public:
    RegionSum2DPrefixSum(const vector<vector<int>>& matrix)
        : m_sumMatrix(matrix) {
        size_t rowSize = matrix.size(), colSize = matrix.empty() ? 0 : matrix.front().size();
        for (size_t row = 1; row < rowSize; ++row) {
            m_sumMatrix[row][0] += m_sumMatrix[row - 1][0];
        }
        for (size_t col = 1; col < colSize; ++col) {
            m_sumMatrix[0][col] += m_sumMatrix[0][col - 1];
        }

        for (size_t row = 1; row < rowSize; ++row) {
            for (size_t col = 1; col < colSize; ++ col) {
                m_sumMatrix[row][col] += (m_sumMatrix[row][col - 1] + m_sumMatrix[row - 1][col] - m_sumMatrix[row - 1][col - 1]);
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
    vector<vector<int>> m_sumMatrix;
};

class RangeSumMultiple1DSegmentTreeByHeap : public RegionSumStrategy {
public:
    RangeSumMultiple1DSegmentTreeByHeap(const vector<vector<int>>& matrix)
        : m_size(matrix.empty() ? 0 : matrix.front().size())
        , m_sumMatrix(matrix.size()) {
        if (0 < m_size) {
            for (size_t i = 0; i < matrix.size(); ++ i) {
                build(0, m_size - 1, 0, m_sumMatrix[i], matrix[i]);
            }
        }
    }

    int sum(size_t rowLo, size_t colLo, size_t rowHi, size_t colHi) const {
        int ans = 0;
        for (size_t row = rowLo; row <= rowHi; ++ row) {
            ans += query(0, m_size - 1, 0, m_sumMatrix[row], colLo , colHi);
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
            return query(lo, mid, lftChildIndex(parent), sums, i, j) + query(mid + 1, hi, rhtChildIndex(parent), sums, i, j);
        }
    }

    size_t m_size; // per row size, column count
    vector<vector<int>> m_sumMatrix;
};

// RangeSum2DSegmentTreeByHeap is NOT true 2D. It should be updated.
class RangeSum2DSegmentTreeByHeap : public RegionSumStrategy {
public:
    RangeSum2DSegmentTreeByHeap(const vector<vector<int>>& matrix)
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
            return query(lo, mid, lftChildIndex(parent), sums, i, j) + query(mid + 1, hi, rhtChildIndex(parent), sums, i, j);
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
        for (TreeNode* root : m_roots) {
            queue<TreeNode*> q;
            if (root) {
                q.push(root);
            }
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();

                if (node->lft) {
                    q.push(node->lft);
                }
                if (node->rht) {
                    q.push(node->rht);
                }

                delete node;
            }
        }
    }

    int sum(size_t rowLo, size_t colLo, size_t rowHi, size_t colHi) const {
        int ans = 0;
        for (size_t row = rowLo; row <= rowHi; ++ row) {
            ans += query(m_roots[row], colLo , colHi);
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
            parent->lft = build(lo, mid, nums);
            parent->rht = build(mid + 1, hi, nums);
            parent->sum = parent->lft->sum + parent->rht->sum;
        }

        return parent;
    }

    int query(TreeNode* parent, size_t lo, size_t hi) const {
        if (!parent || hi < parent->lo || parent->hi < lo) {
            return 0;
        }

        if (lo <= parent->lo && parent->hi <= hi) {
            return parent->sum;
        }
        else {
            return query(parent->lft, lo, hi) + query(parent->rht, lo, hi);
        }
    }

    vector<TreeNode*> m_roots;
};

class RegionSum2DSegmentTreeByTree : public RegionSumStrategy {
public:
    RegionSum2DSegmentTreeByTree(const vector<vector<int>>& matrix)
        : m_root(matrix.empty() ? nullptr : (matrix.front().empty() ? nullptr : buildRow(0, 0, matrix.size() - 1, matrix.front().size() - 1, matrix))) {
    }

    ~RegionSum2DSegmentTreeByTree() {
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

    TreeNode* m_root;
};

class RegionSumMultiple1DBinaryIndexTree : public RegionSumStrategy {
public:
    RegionSumMultiple1DBinaryIndexTree(const vector<vector<int>>& matrix)
        : m_rowSize(matrix.size())
        , m_colSize(matrix.empty() ? 0 : matrix.front().size())
        , m_sumMatrix(m_rowSize, vector<int>(m_colSize + 1, 0)) {
        for (size_t row = 0; row < m_rowSize; ++row) {
            vector<int>& sums = m_sumMatrix[row];
            const vector<int>& nums = matrix[row];
            for (size_t col = 1; col <= m_colSize; ++col) {
                sums[col] = nums[col - 1];
                for (size_t i = col - lowbit(col) + 1; i < col; ++i) {
                    sums[col] += nums[i - 1];
                }
            }
        }
    }

    int sum(const vector<int>& sums, size_t i) const {
        int ans = 0;
        for (i = i + 1; i != 0; i -= lowbit(i)) {
            ans += sums[i];
        }
        return ans;
    }

    int sum(size_t rowLo, size_t colLo, size_t rowHi, size_t colHi) const {
        int ans = 0;
        for (size_t row = rowLo; row <= rowHi; ++ row) {
            ans += sum(m_sumMatrix[row], colHi);
        }
        if (0 < colLo) {
            for (size_t row = rowLo; row <= rowHi; ++ row) {
                ans -= sum(m_sumMatrix[row], colLo - 1);
            }
        }
        return ans;
    }

private:
    size_t lowbit(size_t x) const {
        return x & ~(x - 1);
    }

    size_t m_rowSize, m_colSize;
    vector<vector<int>> m_sumMatrix;
};

class RegionSum2DBinaryIndexTree : public RegionSumStrategy {
public:
    RegionSum2DBinaryIndexTree(const vector<vector<int>>& matrix)
        : m_rowSize(matrix.size())
        , m_colSize(matrix.empty() ? 0 : matrix.front().size())
        , m_sumMatrix(m_rowSize + 1, vector<int>(m_colSize + 1, 0)) {
        for (size_t row = 0; row < m_rowSize; ++row) {
            for (size_t col = 0; col < m_colSize; ++col) {
                updateTree(row, col, matrix[row][col]);
            }
        }
    }

    int sum(size_t row, size_t col) const {
        int ans = 0;
        for (size_t r = row + 1; r != 0; r -= lowbit(r)) {
            for (size_t c = col + 1; c != 0; c -= lowbit(c)) {
                ans += m_sumMatrix[r][c];
            }
        }
        return ans;
    }

    int sum(size_t rowLo, size_t colLo, size_t rowHi, size_t colHi) const {
        int ans = sum(rowHi, colHi);
        if (0 < rowLo) {
            ans -= sum(rowLo - 1, colHi);
            if (0 < colLo) {
                ans -= sum(rowHi, colLo - 1);
                ans += sum(rowLo - 1, colLo - 1);
            }
        }
        else {
            if (0 < colLo) {
                ans -= sum(rowHi, colLo - 1);
            }
        }
        return ans;
    }

private:
    size_t lowbit(size_t x) const {
        return x & ~(x - 1);
    }

    void updateTree(size_t row, size_t col, int val) {
        for (size_t r = row + 1; r <= m_rowSize; r += lowbit(r)) {
            for (size_t c = col + 1; c <= m_colSize; c += lowbit(c)) {
                m_sumMatrix[r][c] += val;
            }
        }
    }

    size_t m_rowSize, m_colSize;
    vector<vector<int>> m_sumMatrix;
};

class NumMatrix {
public:
    NumMatrix(const vector<vector<int>>& matrix) {
        //m_strategy = new RegionSumMultiple1DPrefixSum(matrix);
        m_strategy = new RegionSum2DPrefixSum(matrix);

        //m_strategy = new RangeSumMultiple1DSegmentTreeByHeap(matrix);
        //m_strategy = new RangeSum2DSegmentTreeByHeap(matrix);

        //m_strategy = new RegionSumMultiple1DSegmentTreeByTree(matrix);
        //m_strategy = new RegionSum2DSegmentTreeByTree(matrix);

        //m_strategy = new RegionSumMultiple1DBinaryIndexTree(matrix);
        //m_strategy = new RegionSum2DBinaryIndexTree(matrix);
    }

    ~NumMatrix() {
        delete m_strategy;
    }

    int sumRegion(size_t rowLo, size_t colLo, size_t rowHi, size_t colHi) const {
        assert(rowLo <= rowHi && colLo <= colHi);
        return m_strategy->sum(rowLo, colLo, rowHi, colHi);
    }

private:
    RegionSumStrategy* m_strategy;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */