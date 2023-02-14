class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            std::swap(a, b);
        }

        bool carry = false;
        for (int i = a.size() - 1, j = b.size() - 1; (0 <= i) && (0 <= j || carry); --i, --j) {
            int v = (a[i] - '0') + (0 <= j ? (b[j] - '0') : 0) + (carry ? 1 : 0);
            carry = (2 <= v);
            a[i] = '0' + v % 2;
        }
        if (carry) {
            a.insert(a.begin(), '1');
        }

        return a;
    }
};
