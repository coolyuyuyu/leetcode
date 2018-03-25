class Solution {
public:

    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }

        unordered_multimap<string, string> similarities;
        for (size_t i = 0; i < pairs.size(); ++i) {
            similarities.emplace(pairs[i].first, pairs[i].second);
            similarities.emplace(pairs[i].second, pairs[i].first);
        }

        size_t len = words1.size();
        for (size_t i = 0; i < len; ++i) {
            if (words1[i] != words2[i]) {
                bool found = false;
                auto range = similarities.equal_range(words1[i]);
                for (auto it = range.first; !found && it != range.second; ++it) {
                    if (it->second == words2[i]) {
                        found = true;
                    }
                }
                if (!found) {
                    return false;
                }
            }
        }

        return true;
    }
};