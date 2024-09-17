class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> cnts;
        for (const string& s : {s1, s2}) {
            string word;
            for (istringstream iss(s); iss >> word;) {
                ++cnts[word];
            }
        }

        vector<string> ret;
        for (const auto& [word, cnt] : cnts) {
            if (cnt == 1) {
                ret.push_back(word);
            }
        }

        return ret;
    }
};
