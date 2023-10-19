class Solution {
public:
    int countAsterisks(string s) {
        vector<string> words(1);
        for (char c : s) {
            if (c == '|') {
                words.emplace_back();
            }
            else {
                words.back().push_back(c);
            }
        }

        int ret = 0;
        for (int i = 0; i < words.size(); i += 2) {
            ret += std::count(words[i].begin(), words[i].end(), '*');
        }

        return ret;
    }
};
