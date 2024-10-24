class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> capitlization;
        unordered_map<string, string> vowelerror;
        for (const string& word : wordlist) {
            string key = word;
            for (auto& c : key) {
                if (std::isupper(c)) {
                    c = std::tolower(c);
                }
            }
            capitlization.emplace(key, word);

            for (auto& c : key) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    c = '*';
                }
            }
            vowelerror.emplace(key, word);
        }

        int n = queries.size();
        vector<string> ret(n);
        for (int i = 0; i < n; ++i) {
            string query = queries[i];

            if (words.find(query) != words.end()) {
                ret[i] = query;
                continue;
            }

            for (auto& c : query) {
                if (std::isupper(c)) {
                    c = std::tolower(c);
                }
            }
            if (capitlization.find(query) != capitlization.end()) {
                ret[i] = capitlization[query];
                continue;
            }

            for (auto& c : query) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    c = '*';
                }
            }
            if (vowelerror.find(query) != vowelerror.end()) {
                ret[i] = vowelerror[query];
            }
        }

        return ret;
    }
};
