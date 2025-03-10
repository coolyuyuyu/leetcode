class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        std::function<int(char)> getVowelIdx = [](char c) {
            switch (c) {
            case 'a': return 0;
            case 'e': return 1;
            case 'i': return 2;
            case 'o': return 3;
            case 'u': return 4;
            default: return -1;
            };
        };

        int n = word.size();

        // rhtVCnts[i]: the number of consecutive vowels to the right of i (including i)
        int rhtVCnts[n + 1];
        rhtVCnts[n] = 0;
        for (int i = n; 0 < i--;) {
            if (getVowelIdx(word[i]) >= 0) {
                rhtVCnts[i] = 1 + rhtVCnts[i + 1];
            }
            else {
                rhtVCnts[i] = 0;
            }
        }

        vector<int> vCnts(5, 0);
        int diffVCnt = 0;
        int cCnt = 0;

        long long ret = 0;
        for (int i = 0, j = 0, n = word.size(); i < n; ++i) {
            for (; j < n && (diffVCnt < 5 || cCnt < k); ++j) {
                int idx = getVowelIdx(word[j]);
                if (idx >= 0) {
                    if (++vCnts[idx] == 1) {
                        ++diffVCnt;
                    }
                }
                else {
                    ++cCnt;
                }
            }

            if (diffVCnt == 5 && cCnt == k) {
                ret += 1;
                ret += rhtVCnts[j];
            }

            int idx = getVowelIdx(word[i]);
            if (idx >= 0) {
                if (--vCnts[idx] == 0) {
                    --diffVCnt;
                }
            }
            else {
                --cCnt;
            }
        }

        return ret;
    }
};
