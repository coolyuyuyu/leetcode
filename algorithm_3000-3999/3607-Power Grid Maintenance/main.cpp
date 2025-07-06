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
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DisjointSets ds(c + 1);
        for (const auto& connection : connections) {
            ds.merge(connection[0], connection[1]);
        }

        vector<bool> state(c + 1, true);

        unordered_map<int, set<int>> root2onlines;
        for (int station = 1; station <= c; ++station) {
            root2onlines[ds.root(station)].insert(station);
        }

        vector<int> ret;
        for (const auto& query : queries) {
            int t = query[0], station = query[1];
            if (t == 1) {
                if (state[station]) {
                    ret.push_back(station);
                }
                else if (root2onlines[ds.root(station)].empty()) {
                    ret.push_back(-1);
                }
                else {
                    ret.push_back(*(root2onlines[ds.root(station)].begin()));
                }
            }
            else if (t == 2 && state[station]) {
                state[station] = false;
                root2onlines[ds.root(station)].erase(station);
            }
        }

        return ret;
    }
};
