class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int indexes[26];
        std::fill(indexes, indexes + 26, -1);

        int ret = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (indexes[s[i] - 'a'] == -1) {
                indexes[s[i] - 'a'] = i;
            }
            else {
                ret = std::max(ret, i - indexes[s[i] - 'a'] - 1);
            }
        }

        return ret;
    }
};
