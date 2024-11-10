class Solution {
public:
    string compressedString(string word) {
        string ret;
        for (int i = 0, n = word.size(); i < n;) {
            int j = i + 1;
            while (j < n && word[i] == word[j] && j - i < 9) {
                ++j;
            }

            ret += '0' + (j - i);
            ret += word[i];

            i = j;
        }

        return ret;
    }
};
