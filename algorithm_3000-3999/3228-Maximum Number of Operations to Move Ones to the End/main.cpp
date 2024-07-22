class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();

        int ret = 0;
        int preCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') { continue; }
            
            int j = i;
            while (j < n && s[j] == '1') {
                ++j;
            }
            int curCnt = j - i;

            ret += preCnt;
            preCnt += curCnt;

            i = j - 1;
        }
        if (s.back() == '0') {
            ret += preCnt;
        }

        return ret;
    }
};
