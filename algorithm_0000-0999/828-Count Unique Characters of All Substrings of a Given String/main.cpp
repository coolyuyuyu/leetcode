class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> indexesArr[26];

        for (int i = 0; i < 26; ++i) {
            indexesArr[i].push_back(-1);
        }
        for (int i = 0, n = s.size(); i < n; ++i) {
            indexesArr[s[i] - 'A'].push_back(i);
        }
        for (int i = 0; i < 26; ++i) {
            indexesArr[i].push_back(s.size());
        }

        long long ret = 0;
        for (const vector<int>& indexes : indexesArr) {
            for (int i = 1; i + 1 < indexes.size(); ++i) {
                ret += (indexes[i] - indexes[i - 1]) * (indexes[i + 1] - indexes[i]);
            }
        }

        return ret;
    }
};
