class RangeSumStrategy {
public:
    virtual void update(size_t i, int val) = 0;
    virtual int sum(size_t lo, size_t hi) const = 0;
};

class RangeSumPrefixSum : public RangeSumStrategy {
public:
    RangeSumPrefixSum(vector<int>& nums)
        : m_nums(nums)
        , m_sums(nums) {
        for (size_t i = 1; i < m_sums.size(); ++i) {
            m_sums[i] += m_sums[i - 1];
        }
    }

    void update(size_t i, int val) {
        int diff = val - m_nums[i];
        m_nums[i] = val;

        for (; i < m_sums.size(); ++i) {
            m_sums[i] += diff;
        }
    }

    int sum(size_t lo, size_t hi) const {
        return m_sums[hi] - (0 < lo ? m_sums[lo - 1] : 0);
    }

private:
    vector<int>& m_nums;
    vector<int> m_sums;
};

class RangeSumSegmentTreeByHeap : public RangeSumStrategy {
public:
    RangeSumSegmentTreeByHeap(vector<int>& nums)
        : m_size(nums.size()) {
        if (0 < m_size) {
            build(0, m_size - 1, 0, nums);
        }
    }

    void update(size_t i, int val) {
        update(0, m_size - 1, 0, i, val);
    }

    int sum(size_t lo, size_t hi) const {
        return query(0, m_size - 1, 0, lo , hi);
    }

private:
    inline size_t lftChildIndex(size_t parent) const {
        return parent * 2 + 1;
    }

    inline size_t rhtChildIndex(size_t parent) const {
        return parent * 2 + 2;
    }

    void build(size_t lo, size_t hi, size_t parent, const vector<int>& nums) {
        assert(lo <= hi);

        if (lo == hi) {
            if (m_sums.size() <= parent) {
                m_sums.resize(parent + 1);
            }
            m_sums[parent] = nums[lo];
            return;
        }

        size_t mid = lo + (hi - lo) / 2;
        size_t lftChild = lftChildIndex(parent), rhtChild = rhtChildIndex(parent);
        build(lo, mid, lftChild, nums);
        build(mid + 1, hi, rhtChild, nums);
        m_sums[parent] = m_sums[lftChild] + m_sums[rhtChild];
    }

    void update(size_t lo, size_t hi, size_t parent, size_t i, int val) {
        assert(lo <= hi);

        if (i < lo || hi < i) {
            return;
        }

        if (lo == hi) {
            assert(i == lo);
            m_sums[parent] = val;
        }
        else {
            size_t mid = lo + (hi - lo) / 2;
            size_t lftChild = lftChildIndex(parent), rhtChild = rhtChildIndex(parent);
            update(lo, mid, lftChild, i, val);
            update(mid + 1, hi, rhtChild, i, val);
            m_sums[parent] = m_sums[lftChild] + m_sums[rhtChild];
        }
    }

    int query(size_t lo, size_t hi, size_t parent, size_t i, size_t j) const {
        assert(lo <= hi);

        if (j < lo || hi < i) {
            return 0;
        }

        if (i <= lo && hi <= j) {
            return m_sums[parent];
        }
        else {
            size_t mid = lo + (hi - lo) / 2;
            return query(lo, mid, lftChildIndex(parent), i, j) + query(mid + 1, hi, rhtChildIndex(parent), i, j);
        }
    }

    size_t m_size;
    vector<int> m_sums;
};

class RangeSumSegmentTreeByTree : public RangeSumStrategy {
public:
    RangeSumSegmentTreeByTree(vector<int>& nums)
        : m_root(nums.empty() ? nullptr : build(0, nums.size() - 1, nums)) {
    }

    ~RangeSumSegmentTreeByTree() {
        queue<TreeNode*> q;
        if (m_root) {
            q.push(m_root);
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

    void update(size_t i, int val) {
        update(m_root, i, val);
    }

    int sum(size_t lo, size_t hi) const {
        return query(m_root, lo, hi);
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

        size_t lo, hi;
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
            parent->lft = build(lo, mid, nums);;
            parent->rht = build(mid + 1, hi, nums);;
            parent->sum = parent->lft->sum + parent->rht->sum;
        }

        return parent;
    }

    void update(TreeNode* parent, size_t i, int val) {
        if (i < parent->lo || parent->hi < i) {
            return;
        }

        if (parent->lo == parent->hi) {
            assert(parent->lo == i);
            parent->sum = val;
        }
        else {
            update(parent->lft, i, val);
            update(parent->rht, i, val);
            parent->sum = parent->lft->sum + parent->rht->sum;
        }
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

    TreeNode* m_root;
};

class BinaryIndexedTree {
public:
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

class RangeSumBinaryIndexedTree : public BinaryIndexedTree, public RangeSumStrategy {
public:
    RangeSumBinaryIndexedTree(vector<int>& nums)
        : BinaryIndexedTree(nums) {
    }

    void update(size_t i, int val) {
        BinaryIndexedTree::set(i, val);
    }

    int sum(size_t lo, size_t hi) const {
        return BinaryIndexedTree::sum(lo, hi);
    }
};

class NumArray {
public:
    NumArray(vector<int> nums)
        : m_nums(nums) {
        //m_strategy = new RangeSumPrefixSum(m_nums);

        //m_strategy = new RangeSumSegmentTreeByHeap(m_nums);

        //m_strategy = new RangeSumSegmentTreeByTree(m_nums);

        m_strategy = new RangeSumBinaryIndexedTree(m_nums);
    }

    ~NumArray() {
        delete m_strategy;
    }

    void update(size_t i, int val) {
        return m_strategy->update(i, val);
    }

    int sumRange(size_t lo, size_t hi) const{
        if (hi < lo) {
            swap(lo, hi);
        }
        return m_strategy->sum(lo, hi);
    }

private:
    RangeSumStrategy* m_strategy;

    vector<int> m_nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */