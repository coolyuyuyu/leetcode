class Solution {
public:
    class DisjointSet {
    public:
        DisjointSet() {
        }

        int find(int i) {
            while (m_parents.size() <= i) {
                m_parents.push_back(m_parents.size());
            }

            if (m_parents[i] != i) {
                m_parents[i] = find(m_parents[i]);
            }

            return m_parents[i];
        }

        void merge(int i, int j) {
            int rootI = find(i);
            int rootJ = find(j);
            if (rootI != rootJ) {
                m_parents[rootI] = rootJ;
            }
        }


    private:
        vector<int> m_parents;
    };


    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> names; // mail to account name
        unordered_map<string, int> indexes;  // mail to mail index
        DisjointSet ds;
        for (const auto& account : accounts) {
            const string& name = account[0];
            for (size_t i = 1; i < account.size(); ++i) {
                const string& mail = account[i];

                names[mail] = name;
                indexes.emplace(mail, indexes.size());
                ds.merge(indexes[account[1]], indexes[mail]);
            }
        }

        unordered_map<int, vector<string>> mailGroups; // mail groups
        for (const auto& p : names) {
            const string& mail = p.first;
            mailGroups[ds.find(indexes[mail])].push_back(mail);
        }

        for (auto& p : mailGroups) {
             sort(p.second.begin(), p.second.end());
        }

        vector<vector<string>> ans;
        for (const auto& p : mailGroups) {
            const vector<string>& mails = p.second;
            ans.emplace_back();

            vector<string>& account = ans.back();
            account.emplace_back(names[mails[0]]);
            account.insert(account.end(), mails.begin(), mails.end());
        }

        return ans;
    }
};