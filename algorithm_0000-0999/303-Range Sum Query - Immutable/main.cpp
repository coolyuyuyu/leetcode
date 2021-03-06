class RangeSumStrategy {
public:
    virtual int sum(size_t lo, size_t hi) const = 0;
};

class RangeSumPrefixSum : public RangeSumStrategy {
public:
    RangeSumPrefixSum(const vector<int>& nums)
        : m_sums(nums) {
        for (size_t i = 1; i < m_sums.size(); ++i) {
            m_sums[i] += m_sums[i - 1];
        }
    }

    int sum(size_t lo, size_t hi) const {
        return m_sums[hi] - (0 < lo ? m_sums[lo - 1] : 0);
    }

private:
    vector<int> m_sums;
};

class RangeSumSegmentTreeByHeap : public RangeSumStrategy {
public:
    RangeSumSegmentTreeByHeap(const vector<int>& nums)
        : m_size(nums.size()) {
        if (0 < m_size) {
            build(0, m_size - 1, 0, nums);
        }
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
            return query(lo, mid, lftChildIndex(parent), i, j) + query(mid + 1, hi, rhtChildIndex(parent),i, j);
        }
    }

    size_t m_size;
    vector<int> m_sums;
};

class RangeSumSegmentTreeByTree : public RangeSumStrategy {
public:
    RangeSumSegmentTreeByTree(const vector<int>& nums)
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

    TreeNode* m_root;
};

class RangeSumBinaryIndexTree : public RangeSumStrategy {
public:
    RangeSumBinaryIndexTree(const vector<int>& nums)
        : m_sums(nums.size() + 1) {
        for (size_t i = 1; i < m_sums.size(); ++i) {
            m_sums[i] = nums[i - 1];
            for (size_t j = i - lowbit(i) + 1; j < i; ++j) {
                m_sums[i] += nums[j - 1];
            }
        }
    }

    int sum(size_t i) const {
        int ans = 0;
        for (i = i + 1; i != 0; i -= lowbit(i)) {
            ans += m_sums[i];
        }
        return ans;
    }

    int sum(size_t lo, size_t hi) const {
        return sum(hi) - (0 < lo ? sum(lo - 1) : 0);
    }

private:
    size_t lowbit(size_t x) const {
        return x & ~(x - 1);
    }

    vector<int> m_sums;
};

class NumArray {
public:
    NumArray(const vector<int>& nums) {
        m_strategy = new RangeSumPrefixSum(nums);

        //m_strategy = new RangeSumSegmentTreeByHeap(nums);

        //m_strategy = new RangeSumSegmentTreeByTree(nums);

        //m_strategy = new RangeSumBinaryIndexTree(nums);
    }

    ~NumArray() {
        delete m_strategy;
    }

    int sumRange(size_t lo, size_t hi) const{
        if (hi < lo) {
            swap(lo, hi);
        }
        return m_strategy->sum(lo, hi);
    }

private:
    RangeSumStrategy* m_strategy;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */