class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int k0 = 0;;
        for (int i = 0; i < 8; ++i) {
            k0 |= cells[i] << (8 - i - 1);
        }

        unordered_map<int, int> m;
        int i = 0;
        int k = k0;
        for (; m.find(k) == m.end();) {
            m[k] = i;
            k = ~((k >> 1) ^ (k << 1)) & 0b01111110;
            ++i;
        }
        int len = i - m[k];
        if (n >= m[k]) {
            n = m[k] + (n - m[k]) % len;
        }

        k = k0;
        for (int i = 0; i < n; ++i) {
            k = ~((k >> 1) ^ (k << 1)) & 0b01111110;
        }

        vector<int> ret(8);
        for (int i = 0; i < 8; ++i) {
            ret[i] = (k >> (8 - i - 1)) & 1;
        }

        return ret;
    }
};
