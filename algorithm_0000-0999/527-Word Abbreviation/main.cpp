class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        vector<int> pending(words.size());
        std::iota(pending.begin(), pending.end(), 0);

        vector<string> ret(words.size());
        for (int level = 1; !pending.empty(); ++level) {
            unordered_map<string, vector<int>> abbr2Indexes;
            for (int idx : pending) {
                string abbr = words[idx].substr(0, level) + std::to_string(words[idx].size() - level - 1) + words[idx].back();
                if (words[idx].size() <= abbr.size()) {
                    ret[idx] = words[idx];
                }
                else {
                    abbr2Indexes[abbr].push_back(idx);
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
