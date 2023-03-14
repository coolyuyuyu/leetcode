class Solution {
public:
    // Time: O(nlogn)
    int byUniqSort(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

        int ret = 0;
        for (int lft = 0, rht; lft < n; lft = rht) {
            for (rht = lft + 1; rht < n; ++rht) {
                if ((nums[rht - 1] + 1) != nums[rht]) {
                    break;
                }
            }

            ret = std::max(ret, rht - lft);
        }

        return ret;
    }

    class DisjointSets {
    public:
        bool contain(int elem) {
            return m_roots.find(elem) != m_roots.end();
        }

        void insert(int elem) {
            assert(!contain(elem));
            m_roots[elem] = elem;
        }

        void merge(int elem1, int elem2) {
            int root1 = root(elem1), root2 = root(elem2);
            if (root1 != root2) {
                m_roots[root1] = root2;
            }
        }

        int root(int elem) {
            if (m_roots[elem] != elem) {
                m_roots[elem] = root(m_roots[elem]);
            }

            return m_roots[elem];
        }

private:
        unordered_map<int, int> m_roots;
    };

    // Time: O(n)
    int byDisjointSets(const unordered_set<int>& nums) {
        DisjointSets ds;
        for (int num : nums) {
            ds.insert(num);
            if (ds.contain(num - 1)) {
                ds.merge(num, num - 1);
            }
            if (ds.contain(num + 1)) {
                ds.merge(num, num + 1);
            }
        }

        unordered_map<int, int> counts;
        int ret = 0;
        for (int num : nums) {
            ret = std::max(ret, ++counts[ds.root(num)]);
        }

        return ret;
    }

    // Time: O(n)
    int bySet(const unordered_set<int>& nums) {
        int ret = 0;
        for (int num : nums) {
            if (nums.find(num - 1) != nums.end()) {
                continue;
            }

            int count = 1;
            for (; nums.find(num + count) != nums.end() ;++count) {
                ;
            }
            ret = std::max(ret, count);
        }

        return ret;
    }

    int longestConsecutive(vector<int>& nums) {
        //return byUniqSort(nums);
        //return byDisjointSets(unordered_set<int>(nums.begin(), nums.end()));
        return bySet(unordered_set<int>(nums.begin(), nums.end()));
    }
};
