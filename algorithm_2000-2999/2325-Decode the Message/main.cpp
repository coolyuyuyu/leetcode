class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> translator;
        for (char c : key) {
            if (c == ' ') { continue; }
            translator.emplace(c, 'a' + translator.size());
        }

        for (char& c : message) {
            if (c == ' ') { continue; }
            c = translator[c];
        }

        return message;
    }
};
