class Solution {
public:
    string reversePrefix(string s, int k) {
        for (int i = 0; i * 2 < k; ++i) {
            std::swap(s[i], s[k - i - 1]);
        }

        return s;
    }
};
