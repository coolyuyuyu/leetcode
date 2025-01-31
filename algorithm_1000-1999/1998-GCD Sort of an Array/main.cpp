vector<int> findPrimesLT(int n) {
    vector<int> primes;

    bool isPrimes[n];
    std::fill(isPrimes, isPrimes + n, true);
    isPrimes[0] = false;
    if (1 < n) {
        isPrimes[1] = false;
    }

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
        : m_parents(n)
        , m_size(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    bool merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
            --m_size;
            return true;
        }
        return false;
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
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
    int m_size;
};

class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes = findPrimesLT(std::sqrt(1e5 + 1));

        DisjointSets ds(1e5 + 1);
        for (int num : nums) {
            int x = num;
            for (int p : primes) {
                if (x < p) { break; }
                if ((x % p) == 0) {
                    ds.merge(num, p);
                    while ((x % p) == 0) {
                        x /= p;
                    }
                }
            }
            if (x > 1) {
                ds.merge(num, x);
            }
        }

        vector<int> sorted(nums.begin(), nums.end());
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            if (!ds.connected(nums[i], sorted[i])) {
                return false;
            }
        }

        return true;
    }
};
