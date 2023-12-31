class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int indexes[26];
        std::fill(indexes, indexes + 26, -1);

        int ret = -1;
        for (int i = 0; i < s.size(); ++i) {
            int& index = indexes[s[i] - 'a'];
            if (index == -1) {
                index = i;
            }
            else {
                ret = std::max(ret, i - index - 1);
            }
        }

        return ret;
    }
};
