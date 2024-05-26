class Solution {
public:
    string compressedString(string word) {
        string ret;
        for (int i = 0; i < word.size();) {
            int j = i;
            for (; j + 1 < word.size(); ++j) {
                if (word[j + 1] != word[i]) {
                    break;
                }
            }

            for (int cnt = j - i + 1; cnt > 0; cnt -= 9) {
                ret += '0' + std::min(cnt, 9);
                ret += word[i];
            }

            i = j + 1;
        }

        return ret;
    }
};
