class Solution {
public:
    int M = 1e9 + 7;

    int equalDigitFrequency(string s) {
        int n = s.size();

        unordered_set<int> hashs;
        int cnts[10];
        for (int i = 0; i < n; ++i) {
            std::fill(cnts, cnts + 10, 0);
            long long hash = 0;
            for (int j = i; j < n; ++j) {
                hash = (hash * 11 + s[j] - '0' + 1) % M;

                ++cnts[s[j] - '0'];

                bool sameFreq = true;
                for (int k = 0, cnt = -1; k < 10 && sameFreq; ++k) {
                    if (cnts[k] > 0) {
                        if (cnt == -1) {
                            cnt = cnts[k];
                        }
                        else if (cnt != cnts[k]) {
                            sameFreq = false;
                        }
                    }
                }
                if (sameFreq) {
                    hashs.insert(hash);
                }
            }
        }

        return hashs.size();
    }
};
