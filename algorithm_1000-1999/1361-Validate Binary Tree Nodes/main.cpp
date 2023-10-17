class DisjointSets {
public:
    DisjointSets(int n)
        : m_parents(n)
        , m_size(n) {
        std::iota(m_parents.begin(), m_parents.end(), 0);
    }

    void merge(int elem1, int elem2) {
        int root1 = root(elem1), root2 = root(elem2);
        if (root1 != root2) {
            m_parents[root1] = root2;
            --m_size;
        }
    }

    bool connected(int elem1, int elem2) const {
        return root(elem1) == root(elem2);
    }

    int size() const {
        return m_size;
    }

private:
    int root(int elem) const {
        if (m_parents[elem] != elem) {
            m_parents[elem] = root(m_parents[elem]);
        }

        return m_parents[elem];
    }

    mutable vector<int> m_parents;
    int m_size;
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // root contains exactly 0 parent
        // non-root node contains exactly 1 parent
        int in[n];
        for (int i = 0; i < n; ++i) {
            in[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] >= 0 && ++in[leftChild[i]] >= 2) {
                return false;
            }
            if (rightChild[i] >= 0 && ++in[rightChild[i]] >= 2) {
                return false;
            }
        }
        if (std::count(in, in + n, 0) != 1) {
            return false;
        }

        // every node must be connected
        DisjointSets ds(n);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] >= 0) {
                ds.merge(i, leftChild[i]);
            }
            if (rightChild[i] >= 0) {
                ds.merge(i, rightChild[i]);
            }
        }

        return ds.size() == 1;
    }
};
