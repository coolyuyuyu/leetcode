class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        std::function<vector<int>(const string&)> computeCnt = [](const string& word) {
            vector<int> ret(26, 0);
            for (char c : word) {
                ++ret[c - 'a'];
            }
            return ret;
        };

        vector<int> cnts = computeCnt(words[0]);
        for (const string& word : words) {
            vector<int> tmps = computeCnt(word);
            for (int i = 0; i < 26; ++i) {
                cnts[i] = std::min(cnts[i], tmps[i]);
            }
        }

        vector<string> ret;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnts[i]; ++j) {
                ret.emplace_back(1, 'a' + i);
            }
        }

        return ret;
    }
};
