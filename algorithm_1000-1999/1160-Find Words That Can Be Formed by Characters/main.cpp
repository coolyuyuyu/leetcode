class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnts[26];
        std::fill(cnts, cnts + 26, 0);
        for (char c : chars) {
            ++cnts[c - 'a'];
        }

        int ret = 0;
        for (const string& word : words) {
            int tmp[26];
            std::copy(cnts, cnts + 26, tmp);

            bool good = true;
            for (char c : word) {
                if (--tmp[c - 'a'] < 0) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ret += word.size();
            }
        }

        return ret;
    }
};
