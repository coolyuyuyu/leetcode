class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n = words.size();

        int cnts[26];
        std::fill(cnts, cnts + 26, 0);
        int lens[words.size()];
        for (int i = 0; i < n; ++i) {
            for (char c : words[i]) {
                ++cnts[c - 'a'];
            }
            lens[i] = words[i].size();
        }

        int numPairs = 0;
        for (int i = 0; i < 26; ++i) {
            numPairs += cnts[i] / 2;
        }

        std::sort(lens, lens + n);

        for (int i = 0; i < n; ++i) {
            numPairs -= lens[i] / 2;
            if (numPairs < 0) {
                return i;
            }
        }

        return n;
    }
};
