class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n)
        , m_sizes(n, 1) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
            m_sizes[root2] += m_sizes[root1];
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

    int size(int elem) const {
        return m_sizes[root(elem)];
    }

private:
    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

    mutable vector<int> m_parents;
    vector<int> m_sizes;
};

class Solution {
public:
    unordered_set<int> calcPrime(int n) {
        vector<bool> flags(n + 1, true);

        unordered_set<int> primes;
        for (int i = 2; i <= n; ++i) {
            if (!flags[i]) {
                continue;
            }

            primes.insert(i);

            for (int j = i * 2; j <= n; j += i) {
                flags[j] = false;
            }
        }

        return primes;
    }

    long long countPaths(int n, vector<vector<int>>& edges) {
        unordered_set<int> primes = calcPrime(n);

        DisjointSets ds(n + 1);
        for (const auto& edge : edges) {
            if (primes.find(edge[0]) != primes.end()) { continue;}
            if (primes.find(edge[1]) != primes.end()) { continue;}
            ds.merge(edge[0], edge[1]);
        }

        vector<vector<int>> graph(n + 1);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        long long ret = 0;
        for (int root : primes) {
            long long presum = 0;
            for (int child : graph[root]) {
                if (primes.find(child) != primes.end()) { continue; }

                long long cnt = ds.size(child);
                ret += cnt;
                ret += cnt * presum;

                presum += cnt;
            }
        }

        return ret;
    }
};
