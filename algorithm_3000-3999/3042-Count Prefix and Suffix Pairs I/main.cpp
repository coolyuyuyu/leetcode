class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            const auto& str1 = words[i];
            for (int j = i + 1; j < n; ++j) {
                const auto& str2 = words[j];
                if (str2.compare(0, str1.size(), str1) == 0 &&
                    str2.compare(str2.size() - str1.size(), str1.size(), str1) == 0) {
                    ++ret;
                }
            }
        }

        return ret;
    }
};
