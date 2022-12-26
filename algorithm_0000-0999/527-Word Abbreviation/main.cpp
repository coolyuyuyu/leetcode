class Solution {
public:
    // greedy
    vector<string> wordsAbbreviation(vector<string>& words) {
        size_t n = words.size();

        vector<string> ret(n);

        vector<size_t> pending(n);
        std::iota(pending.begin(), pending.end(), 0);
        for (size_t level = 1; !pending.empty(); ++level) {
            map<string, vector<size_t>> abbr2Indexes;
            for (size_t index : pending) {
                const string& word = words[index];
                string abbr = word.substr(0, level) + std::to_string(word.size() - level - 1) + word.back();
                if (abbr.size() < word.size()) {
                    abbr2Indexes[abbr].push_back(index);
                }
                else {
                    ret[index] = word;
                }
            }
            pending.clear();

            for (const auto& [abbr, indexes] : abbr2Indexes) {
                if (indexes.size() == 1) {
                    ret[indexes[0]] = abbr;
                }
                else {
                    pending.insert(pending.end(), indexes.begin(), indexes.end());
                }
            }
        }

        return ret;
    }
};
