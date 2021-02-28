class Solution {
public:
    void generateAbbreviationsbBackTrackV1(const string& word, vector<bool> used, size_t index, vector<string>& abbrs) {
        if (word.size() <= index) {
            string abbr;
            for (size_t index = 0, preIndex = 0; index <= used.size(); ++index) {
                if (index == used.size() || used[index]) {
                    if (preIndex < index) {
                        abbr += to_string(index - preIndex);
                    }

                    if (index < used.size()) {
                        abbr += word[index];
                    }
                    preIndex = index + 1;
                }
            }
            abbrs.emplace_back(abbr);
            return;
        }

        generateAbbreviationsbBackTrackV1(word, used, index + 1, abbrs);
        used[index] = true;
        generateAbbreviationsbBackTrackV1(word, used, index + 1, abbrs);
    }

    void generateAbbreviationsbBackTrackV2(const string& word, size_t pos, size_t count, string& abbr, vector<string>& abbrs) {
        if (word.size() <= pos) {
            abbrs.emplace_back(abbr + (0 < count ? to_string(count) : ""));
            return;
        }

        generateAbbreviationsbBackTrackV2(word, pos + 1, count + 1, abbr, abbrs);

        size_t oldSize = abbr.size();
        if (0 < count) {
            abbr += to_string(count);
        }
        abbr += word[pos];
        generateAbbreviationsbBackTrackV2(word, pos + 1, 0, abbr, abbrs);
        abbr.resize(oldSize);
    }

    vector<string> generateAbbreviationsTopDownV1(const string& word) {
        vector<string> abbrs;
        abbrs.emplace_back(word.empty() ? "" : to_string(word.size()));
        for (size_t i = 0; i < word.size(); ++i) {
            string lft = (0 < i ? to_string(i) : "") + word[i];
            for (const string& rht : generateAbbreviationsTopDownV1(word.substr(i + 1))) {
                abbrs.emplace_back(lft + rht);
            }
        }
        return abbrs;
    }

    const vector<string>& generateAbbreviationsTopDownV2(const string& word, unordered_map<string, vector<string>>& cache) {
        auto p = cache.emplace(word, vector<string>{});
        if (p.second == false) {
            return (p.first)->second;
        }

        vector<string>& abbrs = (p.first)->second;
        abbrs.reserve(pow(2, word.size()));
        abbrs.emplace_back(word.empty() ? "" : to_string(word.size()));
        for (size_t i = 0; i < word.size(); ++i) {
            string lft = (0 < i ? to_string(i) : "") + word[i];
            for (const string& rht : generateAbbreviationsTopDownV2(word.substr(i + 1), cache)) {
                abbrs.emplace_back(lft + rht);
            }
        }

        return abbrs;
    }

    vector<string> generateAbbreviations(string word) {
        /*
        vector<string> abbrs;
        vector<bool> used(word.size(), false);
        generateAbbreviationsbBackTrackV1(word, used, 0, abbrs);
        return abbrs;
        */

        /*
        string abbr;
        vector<string> abbrs;
        generateAbbreviationsbBackTrackV2(word, 0, 0, abbr, abbrs);
        return abbrs;
        */

        /*
        return generateAbbreviationsTopDownV1(word);
        */

        unordered_map<string, vector<string>> cache;
        return generateAbbreviationsTopDownV2(word, cache);
    }
};