class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();

        std::function<int(char)> getVowelIdx = [](char c) {
            switch (c) {
            case 'a': return 0;
            case 'e': return 1;
            case 'i': return 2;
            case 'o': return 3;
            case 'u': return 4;
            default: return -1;
            }
        };

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

        long long ret = 0;

        int vDiffCnt = 0;
        vector<int> vCnts(5, 0);
        int cCnt = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            for (; j < n && (vDiffCnt < 5 || cCnt < k); ++j) {
                int vIdx = getVowelIdx(word[j]);
                if (vIdx >= 0) {
                    if (++vCnts[vIdx] == 1) {
                        ++vDiffCnt;
                    }
                }
                else {
                    ++cCnt;
                }
            }

            if (vDiffCnt == 5 && cCnt == k) {
                ret += 1;
                ret += rhtVCnts[j];
            }

            int vIdx = getVowelIdx(word[i]);
            if (vIdx >= 0) {
                if (--vCnts[vIdx] == 0) {
                    --vDiffCnt;
                }
            }
            else {
                --cCnt;
            }
        }

        return ret;
    }
};
