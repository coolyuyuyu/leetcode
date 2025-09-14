class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        std::function<char(char)> f1 = [](char c) {
            return toupper(c);
        };
        std::function<char(char)> f2 = [](char c) {
            return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') ? '*' : c;
        };

        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> capitalization;
        unordered_map<string, string> vowelerror;
        for (const string& word : wordlist) {
            words.insert(word);

            string key1 = word;
            std::transform(key1.begin(), key1.end(), key1.begin(), f1);
            capitalization.emplace(key1, word);

            string key2 = key1;
            std::transform(key2.begin(), key2.end(), key2.begin(), f2);
            vowelerror.emplace(key2, word);
        }

        int n = queries.size();
        vector<string> ret(n);
        for (int i = 0; i < n; ++i) {
            if (words.find(queries[i]) != words.end()) {
                ret[i] = queries[i];
                continue;
            }

            string key1 = queries[i];
            std::transform(key1.begin(), key1.end(), key1.begin(), f1);
            if (capitalization.find(key1) != capitalization.end()) {
                ret[i] = capitalization[key1];
                continue;
            }

            string key2 = key1;
            std::transform(key2.begin(), key2.end(), key2.begin(), f2);
            if (vowelerror.find(key2) != vowelerror.end()) {
                ret[i] = vowelerror[key2];
                continue;
            }
        }

        return ret;
    }
};
