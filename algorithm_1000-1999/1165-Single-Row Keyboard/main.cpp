class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int indexes[26];
        for (int i = 0; i < 26; ++i) {
            indexes[keyboard[i] - 'a'] = i;
        }

        int ret = 0;
        for (int pre = 0, i = 0; i < word.size(); ++i) {
            int cur = indexes[word[i] - 'a'];
            ret += std::abs(cur - pre);
            pre = cur;
        }

        return ret;
    }
};
