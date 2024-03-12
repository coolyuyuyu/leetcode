class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();

        int flags[n];
        std::fill(flags, flags + n, 0);
        for (int i = 0; i < words.size(); ++i) {
            for (char c : words[i]) {
                flags[i] |= 1 << (c - 'a');
            }
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((flags[i] & flags[j]) == 0) {
                    ret = std::max<int>(ret, words[i].size() * words[j].size());
                }
            }
        }

        return ret;
    }
};
