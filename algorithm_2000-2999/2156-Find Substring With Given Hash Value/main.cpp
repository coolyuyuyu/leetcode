class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size();

        long long M = modulo;

        long long pk = 1;
        for (int i = 0; i + 1 < k; ++i) {
            pk = pk * power % M;
        }

        long long h = 0;
        int pos;
        for (int i = n; 0 < i--;) {
            if (i + k < n) {
                h = h - (s[i + k] - 'a' + 1) * pk % M;
                h = (h + M) % M;
            }
            h = h * power % M;
            h = (h + s[i] - 'a' + 1) % M;

            if (i + k - 1 < n && h == hashValue) {
                pos = i;
            }
        }

        return s.substr(pos, k);
    }
};
