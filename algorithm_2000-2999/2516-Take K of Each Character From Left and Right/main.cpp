class Solution {
public:
    int hash_presum(const string& s, int k) {
        if (k == 0) {
            return 0;
        }
        int n = s.size();

        int totalA = 0, totalB = 0, totalC = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == 'a') {
                ++totalA;
            }
            else if (c == 'b') {
                ++totalB;
            }
            else if (c == 'c') {
                ++totalC;
            }
        }
        
        if (!(k <= totalA && k <= totalB && k <= totalC)) {
            return -1;
        }


        int maxRetainLen = INT_MIN;

        map<int, int> cntIndexA, cntIndexB, cntIndexC;
        cntIndexA[0] = -1;
        cntIndexB[0] = -1;
        cntIndexC[0] = -1;
        for (int aCnt = 0, bCnt = 0, cCnt = 0, i = 0; i < n; ++i) {
            char c = s[i];
            if (c == 'a') {
                ++aCnt;
            }
            else if (c == 'b') {
                ++bCnt;
            }
            else if (c == 'c') {
                ++cCnt;
            }

            auto itrA = cntIndexA.lower_bound(k - (totalA - aCnt));
            auto itrB = cntIndexB.lower_bound(k - (totalB - bCnt));
            auto itrC = cntIndexC.lower_bound(k - (totalC - cCnt));
            if (itrA != cntIndexA.end() && itrB != cntIndexB.end() && itrC != cntIndexC.end()) {
                int i1 = i - itrA->second;
                int i2 = i - itrB->second;
                int i3 = i - itrC->second;
                int p = std::min({ i1,i2,i3 });
                maxRetainLen = std::max(maxRetainLen, p);
            }

            cntIndexA.emplace(aCnt, i);
            cntIndexB.emplace(bCnt, i);
            cntIndexC.emplace(cCnt, i);
        }

        if (maxRetainLen == INT_MIN) {
            return s.size();
        }
        else {
            return s.size() - maxRetainLen;
        }
    }

    int takeCharacters(string s, int k) {
        return hash_presum(s, k);
    }
};
