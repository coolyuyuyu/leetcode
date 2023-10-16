class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int presum[n];
        presum[0] = (s[0] == '1' ? 1 : 0);
        for (int i = 1; i < n; ++i) {
            presum[i] = presum[i - 1] + (s[i] == '1' ? 1 : 0);
        }
        std::function<int(int, int)> cntOnes = [&](int lft, int rht) {
            return presum[rht] - (lft > 0 ? presum[lft - 1] : 0);
        };

        for (int len = 1; len <= n; ++len) {
            string ret;
            for (int lft = 0, rht = lft + len - 1; rht < n; ++lft, ++rht) {
                if (cntOnes(lft, rht) == k) {
                    string tmp = s.substr(lft, len);
                    if (ret.empty()) {
                        ret = tmp;
                    }
                    else if (tmp < ret) {
                        ret = tmp;
                    }
                }
            }
            if (!ret.empty()) {
                return ret;
            }
        }

        return "";
    }
};
