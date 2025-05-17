class Solution {
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        unordered_map<string, string> key2val;
        for (const auto& replacement : replacements) {
            key2val[replacement[0]] = replacement[1];
        }

        unordered_map<string, string> cache;
        std::function<string(const string&)> f = [&](const string& text) {
            if (cache.find(text) != cache.end()) {
                return cache[text];
            }

            string& ret = cache[text];
            for (int i = 0, n = text.size(); i < n;) {
                if (text[i] != '%') {
                    ret += text[i++];
                }
                else {
                    int j;
                    for (j = i + 1; j < n; ++j) {
                        if (text[j] == '%') {
                            break;
                        }
                    }

                    string key = text.substr(i + 1, j - i - 1);
                    ret += f(key2val[key]);
                    i = j + 1;
                }
            }

            return ret;
        };

        return f(text);
    }
};
