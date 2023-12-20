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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mail2id;
        unordered_map<int, string> id2mail;
        unordered_map<int, string> id2name;
        for (const auto& account : accounts) {
            const string& name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                const string& mail = account[i];
                const auto& [_, id] = *(mail2id.emplace(mail, mail2id.size()).first);
                id2mail[id] = mail;
                id2name[id] = name;
            }
        }

        DisjointSets ds(mail2id.size());
        for (const auto& account : accounts) {
            int id1 = mail2id[account[1]];
            for (int i = 2; i < account.size(); ++i) {
                int id2 = mail2id[account[i]];
                ds.merge(id1, id2);
            }
        }

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < mail2id.size(); ++i) {
            groups[ds.root(i)].push_back(i);
        }

        vector<vector<string>> ret;
        for (auto& [_, ids] : groups) {
            vector<string> account;
            account.push_back(id2name[ids[0]]);
            for (int id : ids) {
                account.push_back(id2mail[id]);
            }
            std::sort(account.begin() + 1, account.end());

            ret.push_back(std::move(account));
        }

        return ret;
    }
};
