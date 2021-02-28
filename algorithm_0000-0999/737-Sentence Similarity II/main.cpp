class Solution {
public:
    class DisjointSet {
    public:
        DisjointSet() {
        }

        bool same(const string& word1, const string& word2) {
            return find(getIndex(word1)) == find(getIndex(word2));
        }

        void merge(const string& word1, const string& word2) {
            merge(getIndex(word1), getIndex(word2));
        }

    private:
        int getIndex(const string& word) {
            auto p = m_dict.emplace(word, m_parents.size());
            if (p.second) {
                m_parents.push_back(m_parents.size());
            }
            return p.first->second;
        }

        int find(int i) {
            if (m_parents[i] != i) {
                m_parents[i] = find(m_parents[i]);
            }

            return m_parents[i];
        }

        void merge(int i, int j) {
            int rootI = find(i);
            int rootJ = find(j);
            m_parents[rootI] = rootJ;
        }

        vector<int> m_parents;
        unordered_map<string, int> m_dict;
    };

    bool areWordsSimilar(DisjointSet& ds, const string& word1, const string& word2) {
        return ds.same(word1, word2);
    }

    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }

        DisjointSet ds;
        for (const pair<string, string>& wordPair : pairs) {
            ds.merge(wordPair.first, wordPair.second);
        }

        size_t n = words1.size();
        for (size_t i = 0; i < n; ++i) {
            if (!ds.same(words1[i], words2[i])) {
                return false;
            }
        }

        return true;
    }
};