class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        istringstream iss(text);
        for (string token; iss >> token;) {
            words.push_back(token);
        }

        vector<string> ret;
        for (int i = 2; i < words.size(); ++i) {
            if (words[i - 2] == first && words[i - 1] == second) {
                ret.push_back(words[i]);
            }
        }

        return ret;
    }
};
