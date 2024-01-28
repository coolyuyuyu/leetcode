class Solution {
public:
    int minimumPushes(string word) {
        unordered_set<char> chars(word.begin(), word.end());
        int charCnt = chars.size();

        int ret = 0;
        for (int press = 1; charCnt > 0; ++press) {
            int selectedCnt = std::min(charCnt, 8);
            ret += selectedCnt * press;
            charCnt -= selectedCnt;
        }

        return ret;
    }
};
