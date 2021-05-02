class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        auto genCounts = [](const string& str) -> vector<int> {
            vector<int> counts(26, 0);
            for (char c : str) {
                ++counts[c - 'a'];
            }

            return counts;
        };

        vector<int> commonCounts = genCounts(A[0]);
        for (const string& str : A) {
            vector<int> counts = genCounts(str);
            for (size_t i = 0; i < 26; ++i) {
                commonCounts[i] = min(commonCounts[i], counts[i]);
            }
        }

        vector<string> ret;
        for (size_t i = 0; i < 26; ++i) {
            for (int j = 0; j < commonCounts[i]; ++j) {
                ret.emplace_back(1, 'a' + i);
            }
        }
        return ret;
    }
};
