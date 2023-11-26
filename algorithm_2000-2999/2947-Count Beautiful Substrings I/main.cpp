class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.size();

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int v = 0, c = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
                    ++v;
                }
                else {
                    ++c;
                }

                if (v == c && (v * c) % k == 0) {
                    ++ret;
                }
            }
        }

        return ret;

    }
};