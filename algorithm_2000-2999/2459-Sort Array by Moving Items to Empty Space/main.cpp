class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n)
        , m_cardinality(n, 1)
        , m_size(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
            m_cardinality[root2] += m_cardinality[root1];
            --m_size;
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

    int cardinality(int elem) const {
        return m_cardinality[root(elem)];
    }

    int size() const {
        return m_size;
    }

    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

private:
    mutable vector<int> m_parents;
    vector<int> m_cardinality;
    int m_size;
};

class Solution {
public:
    int byIndexSort(vector<int>& nums) {
        std::function<int(vector<int>)> f = [](vector<int> nums) {
            int n = nums.size();

            int ret = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == i) { continue; }
                if (i != 0) { ret += 2; }
                while (nums[i] != i) {
                    std::swap(nums[i], nums[nums[i]]);
                    ++ret;
                }
            }

            return ret;
        };

        int ret1 = f(nums);

        std::rotate(nums.begin(),nums.begin() + nums.size() - 1, nums.end());
        int ret2 = f(nums);

        return std::min(ret1, ret2);
    }

    int byDisjointSets(vector<int>& nums) {
        std::function<int(vector<int>)> f = [](vector<int> nums) {
            int n = nums.size();
            DisjointSets ds(n);

            for (int i = 0; i < n; ++i) {
                ds.merge(nums[i], nums[nums[i]]);
            }

            int ret = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == i) { continue; }
                if (ds.root(i) == i) {
                    if (ds.connected(i, 0)) {
                        ret += ds.cardinality(i) - 1;
                    }
                    else {
                        ret += ds.cardinality(i) + 1;
                    }
                }
            }

            return ret;
        };

        int ret1 = f(nums);

        std::rotate(nums.begin(),nums.begin() + nums.size() - 1, nums.end());
        int ret2 = f(nums);

        return std::min(ret1, ret2);
    }

    int sortArray(vector<int>& nums) {
        //return byIndexSort(nums);
        return byDisjointSets(nums);
    }
};
