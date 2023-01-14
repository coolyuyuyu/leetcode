class Solution {
public:
    class DisjointSets {
    public:
        DisjointSets()
            : m_parents(26){
            std::iota(m_parents.begin(), m_parents.end(), 'a');
        }

        void merge(char elem1, char elem2) {
            char root1 = root(elem1);
            char root2 = root(elem2);
            if (root1 != root2) {
                m_parents[root1 - 'a'] = root2;
            }
        }

        vector<vector<char>> sets() {
            map<char, vector<char>> groups;
            for (char c = 'a'; c <= 'z'; ++c) {
                groups[root(c)].push_back(c);
            }

            vector<vector<char>> ret;
            for (auto& [_, group] : groups) {
                ret.insert(ret.end(), std::move(group));
            }

            return ret;
        }

    private:
        char root(char elem) {
            if (m_parents[elem - 'a'] != elem) {
                m_parents[elem - 'a'] = root(m_parents[elem - 'a']);
            }

            return m_parents[elem - 'a'];
        }

        vector<char> m_parents;
    };

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSets ds;
        for (size_t i = 0; i < s1.size(); ++i) {
            ds.merge(s1[i], s2[i]);
        }

        vector<char> bases(26);
        for (const vector<char>& group : ds.sets()) {
            for (char c : group) {
                bases[c - 'a'] = group.front();
            }
        }

        string ret(baseStr.size(), 0);
        for (size_t i = 0; i < ret.size(); ++i) {
            ret[i] = bases[baseStr[i] - 'a'];
        }

        return ret;
    }
};
