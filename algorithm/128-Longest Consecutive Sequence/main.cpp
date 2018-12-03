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

    int longestConsecutiveDisjointSet(vector<int>& nums) {
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

    int longestConsecutiveLinearSearch(vector<int>& nums) {
        int ans = 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        for (int num : numSet) {
            if (numSet.find(num - 1) != numSet.end()) {
                continue;
            }

            int count = 1;
            while (numSet.find(num + count) != numSet.end()) {
                ++count;
            }
            ans = max(ans, count);
        }

        return ans;
    }

    int longestConsecutive(vector<int>& nums) {
        //return longestConsecutiveDisjointSet(nums);

        return longestConsecutiveLinearSearch(nums);
    }
};