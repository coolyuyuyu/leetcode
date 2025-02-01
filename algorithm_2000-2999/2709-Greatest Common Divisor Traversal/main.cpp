vector<int> findPrimesLT(int n) {
    vector<int> primes;

    bool isPrimes[n];
    std::fill(isPrimes, isPrimes + n, true);

    for (int i = 2, limit = ceil(sqrt(n)); i < n; ++i) {
        if (isPrimes[i]) {
            primes.push_back(i);
        }
        else {
            continue;
        }

        if (i < limit) {
            for (int j = i * i; j < n; j += i) {
                isPrimes[j] = false;
            }
        }
    }

    return primes;
}

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

private:
    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

    mutable vector<int> m_parents;
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        if (nums.size() > 1 && std::find(nums.begin(), nums.end(), 1) != nums.end()) {
            return false;
        }

        vector<int> primes = findPrimesLT(*std::max_element(nums.begin(), nums.end()) + 1);
        int m = nums.size(), n = primes.size();

        unordered_map<int, int> prime2idx;
        for (int j = 0; j < n; ++j) {
            prime2idx[primes[j]] = j;
        }

        DisjointSets ds(m + n);
        for (int i = 0; i < m; ++i) {
            int num = nums[i];
            for (int j = 0; j < n && primes[j] * primes[j] <= num; ++j) {
                if (num % primes[j] == 0) {
                    ds.merge(i, m + j);
                    do {
                        num /= primes[j];
                    } while (num % primes[j] == 0);
                }
            }
            if (num > 1) {
                ds.merge(i, m + prime2idx[num]);
            }
        }

        for (int i = 1; i < m; ++i) {
            if (!ds.connected(0, i)) {
                return false;
            }
        }

        return true;
    }
};
