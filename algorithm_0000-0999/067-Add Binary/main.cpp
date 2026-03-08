class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            std::swap(a, b);
        }

        string ret(a.size(), 0);
        int carry = 0;
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0; --i, --j) {
            int v = (a[i] - '0') + (j >= 0 ? b[j] - '0' : 0) + carry;
            carry = (v > 1 ? 1 : 0);
            ret[i] = '0' + (v & 1);
        }
        if (carry) {
            ret.insert(ret.begin(), '1');
        }

        return ret;
    }
};
