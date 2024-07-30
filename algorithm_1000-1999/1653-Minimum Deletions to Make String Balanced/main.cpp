class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        int cntLftB[n];
        cntLftB[0] = (s[0] == 'b' ? 1 : 0);
        for (int i = 1; i < n; ++i) {
            cntLftB[i] = cntLftB[i - 1] + (s[i] == 'b' ? 1 : 0);
        }

        int cntRhtA[n];
        cntRhtA[n - 1] = (s[n - 1] == 'a' ? 1 : 0);
        for (int i = n - 2; i >= 0; --i) {
            cntRhtA[i] = cntRhtA[i + 1] + (s[i] == 'a' ? 1 : 0);
        }

        int ret = std::min(cntLftB[n - 1], cntRhtA[0]);
        for (int i = 0; i + 1 < n; ++i) {
            ret = std::min(ret, cntLftB[i] + cntRhtA[i + 1]);
        }

        return ret;
    }
};
