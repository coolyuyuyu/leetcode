class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const string& s1, const string& s2) { return s1.size() < s2.size(); });

        vector<string> ret;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (words[j].find(words[i]) != string::npos) {
                    ret.push_back(words[i]);
                    break;
                }
            }
        }

        return ret;
    }
};
