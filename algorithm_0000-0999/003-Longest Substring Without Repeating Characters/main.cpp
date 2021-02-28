class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int length = 0;
        vector<int> indexes(256, -1);
        for (int i = 0; i < s.size(); ++i) {
            start = max(start, indexes[s[i]] + 1);
            indexes[s[i]] = i;
            length = max(length, i - start + 1);
        }

        return length;
    }
};