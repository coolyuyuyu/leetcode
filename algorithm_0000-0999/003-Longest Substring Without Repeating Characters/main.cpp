class Solution {
public:
    // Time: O(N^2)
    int quadratic(const string& s) {
        size_t maxLen = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            set<char> chars;
            for (size_t j = i; j < s.size(); ++j) {
                if (chars.insert(s[j]).second == false) {
                    break;
                }
            }
            maxLen = std::max(maxLen, chars.size());
        }

        return maxLen;
    }

    // Time: O(N^2)
    int linerar(const string& s) {
        vector<int> indexes(256, -1);
        int maxLen = 0;
        for (int i = 0, start = 0; i < s.size(); ++i) {
            start = std::max(start, indexes[s[i]] + 1); // no repeating from start to ...
            indexes[s[i]] = i;
            maxLen = std::max(maxLen, i - start + 1);
        }

        return maxLen;
    }

    int lengthOfLongestSubstring(string s) {
        //return quadratic(s);
        return linerar(s);
    }
};
