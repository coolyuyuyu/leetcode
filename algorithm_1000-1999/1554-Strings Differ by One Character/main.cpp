class Solution {
public:
    typedef unsigned long long ULL;

    bool differByOne(vector<string>& dict) {
        int m = dict.size(), n = dict[0].size();

        ULL base = 26;

        ULL hashs[m];
        for (int i = 0; i < m; ++i) {
            ULL hash = 0;
            for (int j = 0; j < n; ++j) {
                hash = hash * base + (dict[i][j] - 'a');
            }
            hashs[i] = hash;
        }

        ULL power = 1;
        for (int j = n; 0 < j--; power *= base) {
            unordered_set<ULL> s;
            for (int i = 0; i < m; ++i) {
                int hash = hashs[i] - (dict[i][j] - 'a') * power;
                if (s.insert(hash).second == false) {
                    return true;
                }
            }
        }

        return false;
    }
};
