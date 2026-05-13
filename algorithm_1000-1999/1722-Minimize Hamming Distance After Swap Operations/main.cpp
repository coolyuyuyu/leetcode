class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

private:
    mutable vector<int> m_parents;
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        DisjointSets ds(n);
        for (const auto& swap : allowedSwaps) {
            int a = swap[0], b = swap[1];
            ds.merge(a, b);
        }

        unordered_map<int, vector<int>> root2group;
        for (int i = 0; i < n; ++i) {
            root2group[ds.root(i)].push_back(i);
        }

        int ret = 0;
        for (const auto& [_, group] : root2group) {
            unordered_map<int, int> num2cnt;
            for (int i : group) {
                if (source[i] != target[i]) {
                    ++num2cnt[source[i]];
                    --num2cnt[target[i]];
                }
            }

            int total = 0;
            for (const auto& [_, cnt] : num2cnt) {
                total += std::abs(cnt);
            }

            ret += total / 2;
        }

        return ret;
    }
};
