class Strategy {
public:
    virtual int getKthAncestor(int node, int k) = 0;
};

class LinearLift : public Strategy {
public:
    LinearLift(int n, vector<int>& parent)
        : m_parent(parent) {
    }

    int getKthAncestor(int node, int k) {
        while (k-- && node != -1) {
            node = m_parent[node];
        }

        return node;
    }

private:
    const vector<int> m_parent;
};

int kDepth = 5e4;

class BinaryLift : public Strategy {
public:
    BinaryLift(int n, vector<int>& parent)
        : m_parent(n, vector<int>(log2(kDepth) + 1, -1)) {
        for (int i = 0; i < n; ++i) {
            m_parent[i][0] = parent[i];
        }

        for (int j = 1, m = log2(kDepth); j <= m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (m_parent[i][j - 1] == -1) { continue; }
                m_parent[i][j] = m_parent[m_parent[i][j - 1]][j - 1];
            }

        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; k && node != -1; ++j, k >>= 1) {
            if (k & 1) {
                node = m_parent[node][j];
            }
        }

        return node;
    }

private:
    vector<vector<int>> m_parent;
};

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent)
        //: m_strategy(new LinearLift(n, parent)) {
        : m_strategy(new BinaryLift(n, parent)) {
    }

    int getKthAncestor(int node, int k) {
        return m_strategy->getKthAncestor(node, k);
    }

private:
    Strategy* m_strategy;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
