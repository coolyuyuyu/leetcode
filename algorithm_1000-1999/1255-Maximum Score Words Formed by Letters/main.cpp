class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();

        int cnts[26];
        std::fill(cnts, cnts + 26, 0);
        for (char c : letters) {
            ++cnts[c - 'a'];
        }

        std::function<int(int)> computeScore = [&](int state) {
            int freq[26];
            std::fill(freq, freq + 26, 0);
            for (int i = 0; i < n; ++i) {
                if ((state >> i) & 1) {
                    for (char c : words[i]) {
                        ++freq[c - 'a'];
                    }
                }
            }

            int ret = 0;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] > cnts[i]) { return 0; }
                ret += score[i] * freq[i];
            }

            return ret;
        };

        int ret = 0;
        for (int s = 0; s < (1 << n); ++s) {
            ret = std::max(ret, computeScore(s));
        }

        return ret;
    }
};
