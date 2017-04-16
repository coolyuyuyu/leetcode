class Solution {
public:
    vector<size_t> getNexts(const string& pattern) {
        if (pattern.empty()) {
            return {};
        }
        
        vector<size_t> nexts(pattern.size());
        size_t i = 1, j = 0;
        while (i < pattern.size()) {
            if (j == 0 || pattern[i - 1] == pattern[j - 1]) {
                ++i; ++j;
                if (pattern[i - 1] == pattern[j - 1]) {
                    nexts[i - 1] = nexts[j - 1];
                }
                else {
                    nexts[i - 1] = j;
                }
            }
            else {
                j = nexts[j - 1];
            }
        }
        
        return nexts;
    }

    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) {
            return -1;
        }
        
        vector<size_t> nexts = getNexts(needle);
        size_t i = 1, j = 1;
        while (i <= haystack.size() && j <= needle.size()) {
            if (j == 0 || haystack[i - 1] == needle[j - 1]) {
                ++i; ++j;
            }
            else {
                j = nexts[j - 1];
            }
        }
        
        if (needle.size() < j) {
            return i - needle.size() - 1;
        }
        else {
            return -1;
        }
    }
};