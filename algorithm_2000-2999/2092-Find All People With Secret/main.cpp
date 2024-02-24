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

    void reset(int elem) {
        m_parents[elem] = elem;
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
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        bool know[n];
        std::fill(know, know + n, false);
        know[0] = know[firstPerson] = true;

        sort(meetings.begin(), meetings.end(), [](const auto& m1, const auto& m2){ return m1[2] < m2[2]; });

        DisjointSets ds(n);
        ds.merge(0, firstPerson);

        for (int i = 0; i < meetings.size();) {
            unordered_set<int> group;
            int j;
            for (j = i; j < meetings.size() && meetings[i][2] == meetings[j][2]; ++j) {
                int x = meetings[j][0], y = meetings[j][1];
                ds.merge(x, y);
                group.insert(x);
                group.insert(y);
            }

            for (int person : group) {
                if (ds.connected(0, person)) {
                    know[person] = true;
                }
                else {
                    ds.reset(person);
                }
            }

            i = j;
        }

        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if (know[i]) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
