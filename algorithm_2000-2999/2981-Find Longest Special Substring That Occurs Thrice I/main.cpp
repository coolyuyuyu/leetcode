class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();

        unordered_map<int, int> len2cntArr[26];

        int ret = -1;
        for (int i = 0; i < n;) {
            int len = 0;
            for (; i + len < n; ++len) {
                if (s[i] != s[i + len]) {
                    break;
                }
            }

            auto& len2cnt = len2cntArr[s[i] - 'a'];
            if ((len2cnt[len] += 1) >= 3) {
                ret = std::max(ret, len);
            }
            if (len >= 2 && (len2cnt[len - 1] += 2) >= 3) {
                ret = std::max(ret, len - 1);
            }
            if (len >= 3) {
                ret = std::max(ret, len - 2);
            }

            i += len;
        }

        return ret;
    }
};
