class Solution {
public:
    class DisjointSet {
    public:
        DisjointSet() {
        }
        int findByNum(int num) {
            return find(getIndex(num));
        }
        void mergeByNum(int num1, int num2) {
            merge(getIndex(num1), getIndex(num2));
        }
    private:
        int getIndex(int num) {
            auto p = m_dict.emplace(num, m_parents.size());
            if (p.second) {
                m_parents.push_back(m_parents.size());
            }
            return p.first->second;
        }
        int find(int i) {
            if (m_parents[i] != i) {
                m_parents[i] = find(m_parents[i]);
            }
            return m_parents[i];
        }
        void merge(int i, int j) {
            int rootI = find(i);
            int rootJ = find(j);
            m_parents[rootI] = rootJ;
        }
        vector<int> m_parents;
        unordered_map<int, int> m_dict;
    };

    int union_find(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        DisjointSet ds;
        for (int num : numSet) {
            if (numSet.find(num - 1) != numSet.end()) {
                ds.mergeByNum(num, num - 1);
            }
            if (numSet.find(num + 1) != numSet.end()) {
                ds.mergeByNum(num, num + 1);
            }
        }
        unordered_map<int, int> rootCounts;
        for (int num : numSet) {
            ++rootCounts[ds.findByNum(num)];
        }
        int maxCount = 0;
        for (auto p : rootCounts) {
            maxCount = max(maxCount, p.second);
        }
        return maxCount;
    }

    // Time: O(nlogn)
    int uniq_sort(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        std::sort(nums.begin(), nums.end());

        int ret = 1;
        for (int cnt = 1, i = 1; i < nums.size(); ++i) {
            if ((nums[i - 1] + 1) == nums[i]) {
                ++cnt;
                ret = std::max(ret, cnt);
            }
            else if (nums[i - 1] == nums[i]) {
            }
            else {
                cnt = 1;
            }
        }

        return ret;
    }

    // Time: O(n)
    int hash_set(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int ret = 0;
        for (const auto& num: s) {
            if (s.find(num - 1) == s.end()) {
                int cnt = 1;
                while (s.find(num + cnt) != s.end()) {
                    ++cnt;
                }

                ret = std::max(ret, cnt);
            }
        }

        return ret;
    }

    int longestConsecutive(vector<int>& nums) {
        //return union_find(nums);
        //return uniq_sort(nums);
        return hash_set(nums);
    }
};
