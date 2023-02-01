class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }

        unordered_map<string, int> word2id;
        auto encode = [&](const string& word) -> int {
            return word2id.emplace(word, word2id.size()).first->second;
        };

        vector<unordered_set<int>> neighbors(sentence1.size() * 2 + similarPairs.size() * 2);
        for (const auto& p : similarPairs) {
            int id1 = encode(p[0]), id2 = encode(p[1]);
            neighbors[id1].insert(id2);
            neighbors[id2].insert(id1);
        }

        auto similiar = [&](const string& word1, const string& word2) -> bool {
            if (word1 == word2) {
                return true;
            }
            else {
                int id1 = encode(word1), id2 = encode(word2);
                return neighbors[id1].find(id2) != neighbors[id1].end();
            }
        };

        for (size_t i = 0; i < sentence1.size(); ++i) {
            if (!similiar(sentence1[i], sentence2[i])) {
                return false;
            }
        }

        return true;
    }
};
