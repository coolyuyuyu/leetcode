class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) { return false; }

        unordered_map<string, unordered_set<string>> neighbor;
        for (const auto& pairs : similarPairs) {
            const string &word1 = pairs[0], &word2 = pairs[1];
            neighbor[word1].insert(word2);
            neighbor[word2].insert(word1);
        }

        for (int i = 0; i < sentence1.size(); ++i) {
            const string &word1 = sentence1[i], &word2 = sentence2[i];
            if (word1 != word2 && neighbor[word1].find(word2) == neighbor[word1].end()) {
                return false;
            }
        }

        return true;
    }
};
