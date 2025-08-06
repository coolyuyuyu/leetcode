class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        int n = words.size();

        queue<int> pendings;
        for (int i = 0; i < n; ++i) {
            pendings.push(i);
        }

        vector<string> ret(n);
        for (int lvl = 1; !pendings.empty(); ++lvl) {
            unordered_map<string, vector<int>> abbr2indexes;
            while (!pendings.empty()) {
                int i = pendings.front();
                pendings.pop();
                const string& word = words[i];
                if (word.size() - lvl - 1 >= 2) {
                    string abbr = word.substr(0, lvl) + std::to_string(word.size() - lvl - 1) + word.back();
                    abbr2indexes[abbr].push_back(i);
                }
                else {
                    ret[i] = words[i];
                }
            }

            for (const auto& [abbr, indexes] : abbr2indexes) {
                if (indexes.size() == 1) {
                    ret[indexes[0]] = abbr;
                }
                else {
                    for (int i : indexes) {
                        pendings.push(i);
                    }
                }
            }
        }

        return ret;
    }
};
