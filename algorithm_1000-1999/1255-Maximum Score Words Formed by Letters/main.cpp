class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();

        vector<int> freq(26, 0);
        for (char c : letters) {
            ++freq[c - 'a'];
        }

        std::function<int(vector<int>, int)> computeScore = [&](vector<int> freq, int state) {
            int ret = 0;
            for (int i = 0; i < n; ++i) {
                if (state & (1 << i)) {
                    for (char c : words[i]) {
                        if (--freq[c - 'a'] < 0) {
                            return 0;
                        }
                        ret += score[c - 'a'];
                    }
                }
            }

            return ret;
        };

        int ret = 0;
        for (int state = 0; state < (1 << n); ++state) {
            ret = std::max(ret, computeScore(freq, state));
        }

        return ret;
    }
};
