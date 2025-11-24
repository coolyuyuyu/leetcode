class Solution {
public:
    int maxOperations(string s) {
        int ret = 0;
        for (int i = 0, n = s.size(), cnt = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++cnt;
            }
            else {
                ret += cnt;

                int j = i;
                while (j < n && s[j] != '1') {
                    ++j;
                }
                i = j - 1;
            }
        }

        return ret;

    }
};
