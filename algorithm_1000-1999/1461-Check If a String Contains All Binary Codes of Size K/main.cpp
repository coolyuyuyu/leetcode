class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> codes;

        for (int i = 0, n = s.size(), code = 0; i < n; ++i) {
            code <<= 1;
            code += (s[i] - '0');
            if (i >= k) {
                code &= ~(1 << k);
            }

            if (i + 1 >= k) {
                codes.insert(code);
            }
        }

        return codes.size() == std::pow(2, k);
    }
};
