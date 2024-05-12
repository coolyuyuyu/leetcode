class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n = s.size();

        vector<int> indexes(26);
        for (int i = 0; i < n; ++i) {
            indexes[s[i] - 'a'] = i;
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += std::abs(i - indexes[t[i] - 'a']);
        }

        return ret;
    }
};
