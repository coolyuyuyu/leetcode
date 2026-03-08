class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        int cntLftB[n];
        cntLftB[0] = (s[0] == 'b');
        for (int i = 1; i < n; ++i) {
            cntLftB[i] = cntLftB[i - 1] + (s[i] == 'b');
        }

        int cntRhtA[n];
        cntRhtA[n - 1] = (s[n - 1] == 'a');
        for (int i = n - 2; i >= 0; --i) {
            cntRhtA[i] = cntRhtA[i + 1] + (s[i] == 'a');
        }

        int ret = std::min(cntRhtA[0], cntLftB[n - 1]);
        for (int i = 1; i < n; ++i) {
            ret = std::min(ret, cntLftB[i - 1] + cntRhtA[i]);
        }

        return ret;
    }
};
