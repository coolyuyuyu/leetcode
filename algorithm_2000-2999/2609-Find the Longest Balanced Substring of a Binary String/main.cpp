class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();

        int ret = 0;
        for (int i = 0; i < n;) {
            int zeroCnt = 0, oneCnt = 0;
            while ((i + zeroCnt) < n && s[i + zeroCnt] == '0') {
                ++zeroCnt;
            }
            while ((i + zeroCnt + oneCnt) < n && s[i + zeroCnt + oneCnt] == '1') {
                ++oneCnt;
            }

            ret = std::max(ret, std::min(zeroCnt, oneCnt) * 2);

            i += (zeroCnt + oneCnt);
        }

        return ret;
    }
};
